class Solution
{
public:
    // linerally iterate through the array
    // mantain start and end index
    // if start == end, return start else start -> end
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;

        // base case
        if (nums.empty())
            return res;
        if (nums.size() == 1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start = nums[0], end = start, next = start + 1;
        // iterate through vector
        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i] == next)
            {
                end = next;

                // avoid overflow
                if (next != 2147483647)
                    next++;

                // last case:
                if (i == nums.size() - 1)
                    res.push_back(to_string(start) + "->" + to_string(end));

                continue;
            }
            // end of the range
            else
            {
                res.push_back(start == end ? to_string(start) : to_string(start) + "->" + to_string(end));
                start = end = nums[i];

                // last case:
                if (i == nums.size() - 1)
                    res.push_back(to_string(start));

                // avoid overflow
                if (start != 2147483647)
                    next = start + 1;
            }
        }

        return res;
    }
};