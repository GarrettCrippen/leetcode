class Solution
{
public:
    // use a sliding window

    int maxVowels(string s, int k)
    {
        int max_count = 0;

        int count = 0;
        int ints = 0;
        // weird for first character
        for (int o = 0; o < s.length(); o++)
        {

            if (s[o] == 'a' || s[o] == 'e' || s[o] == 'i' || s[o] == 'o' || s[o] == 'u')
            {
                count++;
            }

            if (ints >= k)
            {
                if (s[o - k] == 'a' || s[o - k] == 'e' || s[o - k] == 'i' || s[o - k] == 'o' || s[o - k] == 'u')
                    count--;

                max_count = max(max_count, count);
            }
            ints++;
        }

        count = 0;
        ints = 0;
        for (int o = s.length(); o >= 0; o--)
        {

            if (s[o] == 'a' || s[o] == 'e' || s[o] == 'i' || s[o] == 'o' || s[o] == 'u')
            {
                count++;
            }

            if (ints >= k)
            {
                if (s[o + k] == 'a' || s[o + k] == 'e' || s[o + k] == 'i' || s[o + k] == 'o' || s[o + k] == 'u')
                    count--;

                max_count = max(max_count, count);
            }
            ints++;
        }

        return max_count;
    }
};