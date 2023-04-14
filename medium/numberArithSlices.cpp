class Solution
{
public:
    // Note that elements must be consecutive, so effectively we can decrease size of vector if
    //  we find something that is not consecutive

    // we can do this with dp -> store number of consec

    // distance,length
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        vector<pair<int, int>> dp(nums.size(), {INT_MAX, 0});
        int count = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            dp[i].first = nums[i] - nums[i + 1];
            for (int k = i + 1; k < nums.size(); k++)
            {
                // cout<<"dp[i]= {"<<dp[i].first<<","<<dp[i].second<<"}"<<endl;
                // if a link, continue
                if (dp[i].first == dp[k].first)
                {
                    // cout<<"LINK for "<<dp[i].first<<endl;
                    dp[i].second = dp[k].second + 1;
                    count++;
                }
                else
                {
                    dp[i].second = 1;
                    break;
                }
            }
        }
        return count;
    }
};