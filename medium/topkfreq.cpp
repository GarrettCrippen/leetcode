class Solution
{
public:
    // let's create a map and sort it by the value, return first k
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // int as key and freq as value
        map<int, int> mymap;

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            mymap[*it]++;
        }
        vector<pair<int, int>> pairs;
        for (auto it = mymap.begin(); it != mymap.end(); it++)
        {
            pairs.push_back(*it);
        }
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
             { return a.second > b.second; });
        vector<int> res;
        for (auto it = pairs.begin(); it != pairs.begin() + k; it++)
        {
            res.push_back(it->first);
        }
        return res;
    }
};