// the catch is to sort nums before recursing
class Solution
{
public:
    // input is a set
    // output: set of all subsets
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        recurse(nums, 0, vector<int>(), res);

        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));

        return res;
    }

    // can either include or not include value at idx => use backtracking
    void recurse(vector<int> &nums, int idx, vector<int> set, vector<vector<int>> &res)
    {
        // base case;
        if (idx == nums.size())
        {
            res.push_back(set);
            return;
        }

        // Clarification: find subsets, not subsequences

        // include
        set.push_back(nums[idx]);
        recurse(nums, idx + 1, set, res);

        // not include
        set.pop_back();
        recurse(nums, idx + 1, set, res);
    }
};