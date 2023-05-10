class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp = nums;
        vector<int> dp2 = nums;
        vector<bool> ends(nums.size(), false);
        ends[nums.size() - 1] = true;

        // problem if 1st and last included
        for (int i = nums.size() - 1; i > 0; i--)
        {
            for (int k = i + 2; k < nums.size(); k++)
            {
                // keep track if this part touched the end
                if (dp[i] < nums[i] + dp[k])
                {
                    dp[i] = nums[i] + dp[k];
                }
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int k = i + 2; k < nums.size() - 1; k++)
            {
                // keep track if this part touched the end
                if (dp2[i] < nums[i] + dp2[k])
                {
                    dp2[i] = nums[i] + dp2[k];
                }
            }
        }

        return max(*max_element(dp.begin(), dp.end()), *max_element(dp2.begin(), dp2.end()));
    }
};