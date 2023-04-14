class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int leftSum =0;
        int rightSum=0;
        for(int i =0; i<nums.size();i++){
            leftSum+=nums[i];
            rightSum=0;
            for(int k = i+1;k<nums.size();k++){
                rightSum+=nums[k];
            }
            if(rightSum==leftSum-nums[i]) return i;
        }
        return -1;
    }

};

