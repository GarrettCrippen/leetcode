class Solution
{
public:
    // cannot rob two adjacent houses

    // problem: find maxiumum from maximums you can rob from each house

    // input:vector in ints
    int rob(vector<int> &nums)
    {
        vector<int> dp = nums;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int k = i + 2; k < nums.size(); k++)
            {
                dp[i] = max(dp[i], nums[i] + dp[k]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};