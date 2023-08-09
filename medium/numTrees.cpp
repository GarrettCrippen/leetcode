class Solution
{
public:
    // 1:1
    // 2:2
    // 3:5
    // 4:14
    // 5:42
    // 6:132

    // see catalan's number solution for O(n)
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        // iterate to n
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};