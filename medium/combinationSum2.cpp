// input:arr of numbers
// output: arr of combinations of numbers that = target

// each number can only be used once in a combination
// solution=> use backtracking and remove duplicate combinations
class Solution
{
public:
    // problem is duplicates and if the value is very small
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());

        recurse(candidates, target, vector<int>(), 0, 0, -1, res);

        // sort(res.begin(),res.end());
        // auto it = unique(res.begin(),res.end());
        // res.resize(distance(res.begin(),it));
        return res;
    }

    void recurse(vector<int> &candidates, int target, vector<int> comb, int sum, int idx, int prev, vector<vector<int>> &res)
    {

        if (sum > target)
            return;
        if (sum == target)
        {
            // sort(comb.begin(),comb.end());
            res.push_back(comb);
            return;
        }
        if (idx > candidates.size())
            return;

        // check for duplicates here
        for (int i = idx; i < candidates.size(); i++)
        {
            if (candidates[i] == prev)
                continue;

            comb.push_back(candidates[i]);
            recurse(candidates, target, comb, sum + candidates[i], i + 1, prev, res);
            comb.pop_back();
            prev = candidates[i];
        }
    }
};