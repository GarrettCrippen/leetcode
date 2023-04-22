class Solution
{
public:
    // format [pivot..n, 0..n-1]

    // want to search(BINARY) for target

    //**important: all nums are unique
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;

        // observe 2 cases
        //  low < mid < high
        //  low < mid > high
        //  low > mid < high
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            // cout<<"low "<<low<<endl;
            // cout<<"high "<<high<<endl;
            // cout<<"mid "<<mid<<endl;
            // cout<<"---"<<endl;

            if (nums[mid] == target)
                return mid;
            if (nums[low] == target)
                return low;
            if (nums[high] == target)
                return high;

            // case where it is not rotated
            if (nums[low] < nums[high])
            {
                if (nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            // nums[low] > nums[high]

            else if (nums[high] > target and nums[mid] < target)
                low = mid + 1;

            else if (nums[low] < nums[mid] and nums[high] < target and nums[mid] < target)
                low = mid + 1;
            else if (nums[low] > target and nums[mid] < target)
                high = mid - 1;

            else if (nums[low] > nums[mid] and nums[low] > target and nums[mid] > target)
                high = mid - 1;
            else if (nums[high] > target and nums[mid] > target)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return -1;
    }
};