// knapsack 0/1
class Solution
{
public:
    // observation: we can eliminate 'big' values
    // observation: cannot have equal sums if odd
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;

        vector<vector<bool>> b(nums.size() + 1, vector<bool>((sum / 2) + 1));
        b[0][0] = true;

        for (int i = 1; i < b.size(); i++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                if (j - nums[i - 1] >= 0)
                {
                    b[i][j] = b[i - 1][j - nums[i - 1]] || b[i - 1][j];
                }
                else
                {
                    b[i][j] = b[i - 1][j];
                }
            }
        }
        return b[nums.size()][sum / 2];
    }
};