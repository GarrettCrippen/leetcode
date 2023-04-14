class Solution
{
public:
    // input: array
    // output: length: integer

    // don't sort -> o(nlogn)

    // let's create an unordered_map -> store length of sequence, then return maximum of our unordered_map
    int longestConsecutive(vector<int> &nums)
    {
        // int, frequency
        map<int, int> freqs;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (freqs.count(*it - 1) > 0)
                freqs[*it]++;
            else
                freqs[*it] = 1;
        }

        // [1:1,2:1, 3:1] etc....
        for (auto it = freqs.begin(); it != freqs.end(); it++)
        {
            if (freqs.count(it->first + 1) > 0)
            {
                freqs[it->first + 1] = it->second + 1;
                // cout<<freqs[it->first+1]<<endl;
            }
        }

        return max_element(freqs.begin(), freqs.end(), [](auto &a, auto &b)
                           { return a.second < b.second; })
            ->second;
    }
};