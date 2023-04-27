class Solution
{
public:
    // case similar only one solution, but use back tracking
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        recurse(candidates, target, 0, vector<int>(), 0, res);

        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        return res;
    }
    void recurse(vector<int> &candidates, int target, int idx, vector<int> temp, int sum, vector<vector<int>> &res)
    {

        if (sum == target)
            res.push_back(temp);

        if (sum > target)
            return;

        // base case
        if (idx >= candidates.size())
            return;

        // include
        temp.push_back(candidates[idx]);
        sum += candidates[idx];
        recurse(candidates, target, idx + 1, temp, sum, res);
        recurse(candidates, target, idx, temp, sum, res);

        // not include
        temp.pop_back();
        sum -= candidates[idx];
        recurse(candidates, target, idx + 1, temp, sum, res);
    }
};