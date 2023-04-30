class Solution
{
private:
    unordered_map<int, int> mp;

public:
    int climbStairs(int n)
    {
        if (n <= 0)
            return 1;

        if (mp.count(n) > 0)
            return mp[n];

        if (n > 1)
            mp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        else
            mp[n] = climbStairs(n - 1);

        return mp[n];
    }
};