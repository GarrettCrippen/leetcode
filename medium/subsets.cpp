// return all subsets, no duplicates, any order
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> allSets;
        recurse(0, nums, vector<int>(), allSets);
        return allSets;

        // vector<vector<int>>allsets(1,vector<int>());
        // for(int i =0; i<nums.size(); i++){
        //     vector<vector<int>>tempsets=allsets;
        //     for(auto it = tempsets.begin(); it!=tempsets.end();it++)
        //     {

        //     //also add include
        //     vector<int>include = *it;
        //     include.push_back(nums[i]);
        //     allsets.push_back(include);

        //     }
        // }
        // return allsets;
    }
    void recurse(int idx, vector<int> &nums, vector<int> curSet, vector<vector<int>> &allSets)
    {
        if (idx >= nums.size())
        {
            allSets.push_back(curSet);
            return;
        }
        // include current number
        curSet.push_back(nums[idx]);
        recurse(idx + 1, nums, curSet, allSets);

        // no include current number
        curSet.pop_back();
        recurse(idx + 1, nums, curSet, allSets);
    }
};