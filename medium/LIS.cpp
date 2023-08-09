class Solution
{
public:
    // LIS: classic dp problem
    // observe that last element is always increasing
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = nums.size() - 2; i >= 0; i--)
        {

            for (int k = i + 1; k < nums.size(); k++)
            {

                if (nums[k] > nums[i])
                {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};