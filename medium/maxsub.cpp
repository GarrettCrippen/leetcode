#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    // idea is we start at one end of the array and check if we add the next one that we get a larger value
    // compare current value to current value with all of the right

    // need to mantain a dp array of size nums
    vector<int> dp;
    int maxSubArray(vector<int> &nums)
    {
        dp.resize(nums.size());
        dp[nums.size() - 1] = nums[nums.size() - 1];

        // let's iterate backward and find the maximum subarray for each index
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            dp[i] = max(nums[i], nums[i] + dp[i + 1]);
            // cout << dp[i] << endl;
        }

        // find true maximum

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{

    Solution s;
    vector<int> t = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(t) << endl;
    return 0;
}