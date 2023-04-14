// beats 100%
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.length() > t.length())
        {
            return false;
        }

        // let's use two pointers
        int ptr1 = 0;
        int ptr2 = 0;

        // remove first occurence of char
        while (ptr1 < s.length() and ptr2 < t.length())
        {
            if (s[ptr1] == t[ptr2])
            {
                ptr1++;
                ptr2++;
            }
            else
            {
                ptr2++;
            }
        }
        return ptr1 == s.length();
    }
};