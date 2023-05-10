class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res = s.substr(0, 1);

        // for each character check if its the middle of the substring
        for (int i = 0; i < s.length(); i++)
        {
            int l = i, r = i;

            while (l >= 0 && r < s.length() and s[l] == s[r])
            {
                string temp = s.substr(l, r - l + 1);
                if (temp.length() > res.length())
                    res = temp;

                l--;
                r++;
            }

            r = i + 1;
            l = i;
            while (l >= 0 && r < s.length() and s[l] == s[r])
            {
                string temp = s.substr(l, r - l + 1);
                if (temp.length() > res.length())
                    res = temp;

                l--;
                r++;
            }
        }
        return res;
    }
};