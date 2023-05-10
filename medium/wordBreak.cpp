class Solution
{
private:
    // dp for strings
    set<string> dp;

public:
    // input: is a word
    // output: t or false that i can be represnted with the dictionary

    // can try backtracking and dp
    // try erasing every word in the word dict from s and stop when s is empty

    // attempt 1 doesn't work if word breaks down another word in another word and then we remove it
    // solution move left to right to mantain consistency
    // observe pos = 0
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.empty())
            return true;

        bool res = false;
        for (auto it = wordDict.begin(); it != wordDict.end(); it++)
        {

            // check if you can find the dictionary word in the current word
            size_t pos = s.find(*it);
            if (pos != string::npos && pos == 0)
            {

                string cpy = s;
                cpy.erase(pos, it->length());

                // keep track if we computed already or not
                if (dp.count(cpy) > 0)
                    continue;

                dp.insert(cpy);
                res |= wordBreak(cpy, wordDict);
            }
            else
                continue;
        }

        return res;
    }
};