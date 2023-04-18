class Solution
{
public:
    // requirement: constant space
    // cannot modoify nums array

    //[1,n] range, n+1 integers
    //-> use floyd algorithm
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);

        slow = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[fast];

            if (slow == fast)
                return slow;
        }
    }
};