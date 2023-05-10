class Solution
{
public:
    // BFS is slow when result is large => use dfs
    int coinChange(vector<int> &coins, int amount)
    {

        if (amount == 0)
            return 0;
        // at each level
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // strategy is to go through each values Bottom up and fill dp array
        for (int i = 0; i <= amount; i++)
        {
            // greedy strategy does not always work!, so we need to check all paths and find min
            for (auto it = coins.begin(); it != coins.end(); it++)
            {
                if (*it <= i)
                    dp[i] = min(dp[i - *it] + 1, dp[i]);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        else
            return dp[amount];
    }
};