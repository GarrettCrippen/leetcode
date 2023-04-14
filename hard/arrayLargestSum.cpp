class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        // let's use binary search
        int ans = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int m = 0;
            int tempSum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                tempSum += nums[i];
                // if it exceeds mid, then we continue to next subarray
                if (tempSum > mid)
                {
                    tempSum = nums[i];
                    m++;
                }
            }
            cout << "mid is: " << mid << ", m is: " << m << endl;
            // subarray size is too big -> smaller
            if (m < k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};