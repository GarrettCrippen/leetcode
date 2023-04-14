#include <vector>
#include <iostream>
#include <map>

using namespace std;

// RUNTIME O(n), SPACE COMPLEXITY O(n)

class Solution
{
public:
    // idea use a map and check for counter part in the map, if it exists, then add the index
    // otherwise add the number to the map

    // ASSUMPTION ONLY ONE PAIR
    map<int, vector<int>> mymap;
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // counter part found:
            if (mymap.count(target - nums[i]) > 0)
            {
                mymap[target - nums[i]].push_back(i);
                return mymap[target - nums[i]];
            }
            else
            {
                mymap[nums[i]].push_back(i);
            }
        }
        return vector<int>();
    }
};

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
int main()
{

    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = s.twoSum(nums, target);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}