class Solution
{
public:
    // input: array
    // output: list of (list of values that add up to zero) must be unique ex. set()

    // we can consider it an array of 2 sum problems

    vector<vector<int>> twoSum(vector<int> numbers, int target, int index)
    {
        vector<vector<int>> v;
        int i = 0, j = numbers.size() - 1;

        while (i < j)
        {
            vector<int> res;
            if (i == index)
            {
                i++;
                continue;
            }
            if (j == index)
            {
                j--;
                continue;
            }

            int sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                res.push_back(numbers[i]);
                res.push_back(numbers[j]);
                v.push_back(res);
                j--;
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return v;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<int> val;
        for (int i = 0; i < nums.size(); i++)
        {
            if (val.count(nums[i]))
                continue;
            vector<vector<int>> tmp = twoSum(nums, -nums[i], i);
            for (auto it = tmp.begin(); it != tmp.end(); it++)
            {
                vector<int> triplet = *it;
                triplet.push_back(nums[i]);
                sort(triplet.begin(), triplet.end());
                res.push_back(triplet);
            }
            val.insert(nums[i]);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};