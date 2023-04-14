class Solution
{
public:
    // find product of whole array, excluding zeros

    // Requirement: cannot use the divison operation
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> right(nums.size(), 1);
        vector<int> left(nums.size(), 1);

        // idea calculate product to left of i and right of i, then find products of l_i and r_i

        // left side
        for (int i = 1; i < nums.size(); i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
            // cout<<left[i]<<endl;
        }
        // cout<<"--------"<<endl;
        // right side
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
            // cout<<right[i]<<endl;
        }
        vector<int> res;
        // combine
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(right[i] * left[i]);
        }

        return res;
    }
};