class Solution
{
public:
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
};