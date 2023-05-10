// Reference: Shivansh Singh

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size(), count = 0, right = n - 1, MOD = (int)1e9 + 7;

        // pow_mod implementation
        vector<int> power(n, 1);
        power[0] = 1;

        for (int i = 1; i < n; i++)
            power[i] = fmod(power[i - 1] * 2, MOD);

        for (int left = 0; left < n; left++)
        {
            while (right >= left && nums[left] + nums[right] > target)
                right--;

            if (left <= right)
                count = fmod(count + power[right - left], MOD);
        }

        return count;
    }
};