class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size(), -1);
        recurse(cost, dp, 0);
        recurse(cost, dp, 1);

        return min(dp[0], dp[1]);
    }

    int recurse(vector<int> &cost, vector<int> &dp, int idx)
    {
        // either last step or 2nd to last step
        if (idx >= cost.size() - 2)
        {
            dp[idx] = cost[idx];
            return cost[idx];
        }

        if (dp[idx] != -1)
            return dp[idx];

        dp[idx + 1] = recurse(cost, dp, idx + 1);
        dp[idx + 2] = recurse(cost, dp, idx + 2);
        dp[idx] = cost[idx] + min(dp[idx + 1], dp[idx + 2]);

        return dp[idx];
    }
};