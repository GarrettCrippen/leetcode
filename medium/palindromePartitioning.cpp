class Solution
{
public:
    // input: string
    // output: vector st. all strings are palindromes

    // key info: substring is nonempty continguous portion
    // at the minimum a palidrome is a single character => n partitions

    // solution: let's use backtracking => find all partitions and then check if they are palindromes
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> part;
        recurse(s, part, "", vector<string>());

        sort(part.begin(), part.end());
        auto it = unique(part.begin(), part.end());
        part.resize(distance(part.begin(), it));

        return part;
    }

    bool isPalindrome(string s)
    {

        string z = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (iswalnum(s[i]))
            {
                z += tolower(s[i]);
            }
        }
        int p1 = 0;
        int p2 = z.length() - 1;

        while (p1 < p2)
        {
            if (z[p1] != z[p2])
            {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }

    void recurse(string s, vector<vector<string>> &partition, string cur, vector<string> p)
    {
        if (s.empty())
        {

            if (isPalindrome(cur))
            {

                if (cur.length())
                {
                    p.push_back(cur);
                }

                if (p.size())
                    partition.push_back(p);
            }
            return;
        }

        // take a partition of size 1->n

        cur += s[0];
        // if we make a palidrome, then partition

        if (isPalindrome(cur))
        {
            p.push_back(cur);
            recurse(s.substr(1), partition, "", p);
            p.pop_back();
        }

        // make partition larger
        recurse(s.substr(1), partition, cur, p);
    }
};