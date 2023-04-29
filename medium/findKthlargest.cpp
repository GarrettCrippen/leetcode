class Solution
{

    // use a priority queue and pop k times
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        int ans = -1;
        while (k)
        {
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};