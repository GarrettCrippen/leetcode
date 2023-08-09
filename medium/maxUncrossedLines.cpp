class Solution
{
private:
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        // dp here with augmented array
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int k = 0; k < nums2.size(); k++)
            {

                // if equal then add one, then find lcs and move both pointers
                if (nums1[i] == nums2[k])
                {

                    dp[i + 1][k + 1] = dp[i][k] + 1;
                }
                // consider top and left cases
                else
                {

                    dp[i + 1][k + 1] = max(dp[i + 1][k], dp[i][k + 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];

        // map<pair<int,int>,int> mp;
        // return this->recurse(nums1,nums2,0,0,mp);
    }

    // heres memoization method
    int recurse(vector<int> &nums1, vector<int> &nums2, int i, int k, map<pair<int, int>, int> &mp)
    {
        // base case
        if (i == nums1.size() || k == nums2.size())
        {
            return 0;
        }

        if (mp.count({i, k}))
        {
            return mp[{i, k}];
        }

        int res = 0;
        if (nums1[i] == nums2[k])
        {
            mp[{i, k}] = 1 + recurse(nums1, nums2, i + 1, k + 1, mp);
            return mp[{i, k}];
        }
        else
        {
            int left = recurse(nums1, nums2, i + 1, k, mp);
            int right = recurse(nums1, nums2, i, k + 1, mp);
            mp[{i, k}] = max(left, right);
            return mp[{i, k}];
        }
    }
};