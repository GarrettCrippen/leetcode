class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(3, 0));
        dp[0][1] = -prices[0];
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        dp[1][2] = 0;
        for (int i = 2; i <= n; i++)
        {
            // cooldown
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            // buy
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
            // sell
            dp[i][2] = dp[i - 1][1] + prices[i - 1];
        }
        // max of last value for each col
        return max(dp[n][0], max(dp[n][1], dp[n][2]));
    }
};
