class Solution
{
public:
    // observe after nums.size() rotations is redundant like 360,720 degrees

    /*
    let's use binary search where
    min rotations = 0 and max rotations = nums.size()



    */
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        int mid, res = nums[low];
        while (low <= high)
        {

            // observe that are 1..n unique elements and if low < high, then we know low is          minimal
            if (nums[low] < nums[high])
            {
                res = min(res, nums[low]);
                break;
            }
            mid = low + (high - low) / 2;
            res = min(res, nums[mid]);
            // cout<<"nums[low]: "<<nums[low]<<","
            // <<"nums[high]: "<<nums[high]<<endl;

            if (nums[low] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            // cout<<"val mid: "<<nums[mid]<<endl;
        }
        return res;
    }
};