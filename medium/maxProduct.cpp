class Solution
{
public:
    // need to enumerate subarrays.. cannot be greedy b/c negative
    int maxProduct(vector<int> &nums)
    {
        vector<int> dpP = nums;
        vector<int> dpN = nums;

        int neg = nums[nums.size() - 1] < 0 ? 0 : 1;

        // problem is sign
        int res = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // positive
            if (nums[i] >= 0)
            {
                // if positive then just keep old values and multiply by nums
                dpP[i] = max(nums[i], nums[i] * dpP[i + 1]);
                dpN[i] = min(nums[i], nums[i] * dpN[i + 1]);
            }
            // negative
            else
            {
                // if negative then swap current negative value with current positive value
                dpP[i] = max(nums[i], nums[i] * dpN[i + 1]);
                dpN[i] = min(nums[i], nums[i] * dpP[i + 1]);
            }

            // keep track of max positive value
            res = max(res, dpP[i]);
        }

        return res;
    }
};