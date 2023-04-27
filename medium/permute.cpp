class Solution
{
public:
    // let's use backtracking

    // for each idx you can either swap with next one or not
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        recurse(0, nums, res);

        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        return res;
    }

    void recurse(int idx, vector<int> perm, vector<vector<int>> &res)
    {
        if (idx == perm.size() - 1)
        {
            res.push_back(perm);
            return;
        }

        // problem swapping first with second
        // solution: recurse on idx+1 instead of i!
        for (int i = idx + 1; i < perm.size(); i++)
        {

            // here we swap idx and idx+1
            swap(perm[idx], perm[i]);
            recurse(idx + 1, perm, res);

            // swap back
            swap(perm[idx], perm[i]);
            recurse(idx + 1, perm, res);
        }
    }
};