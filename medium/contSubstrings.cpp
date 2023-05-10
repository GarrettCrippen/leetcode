class Solution
{
public:
    // can find largest palindromic substring and reduce
    //  find largers => and then can deduce how many in
    // racecar
    int countSubstrings(string s)
    {
        int count = 0;

        // for each character check if its the middle of the substring
        for (int i = 0; i < s.length(); i++)
        {
            int l = i, r = i;

            while (l >= 0 && r < s.length() and s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }

            r = i + 1;
            l = i;
            while (l >= 0 && r < s.length() and s[l] == s[r])
            {
                count++;

                l--;
                r++;
            }
        }
        return count;
    }
};