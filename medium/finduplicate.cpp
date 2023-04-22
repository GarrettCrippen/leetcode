class Solution {
public:
    //requirement: constant space
    //cannot modoify nums array

    
    //[1,n] range, n+1 integers
        //-> use floyd algorithm
    int findDuplicate(vector<int>& nums) {
        // int slow = 0;
        // int fast = 0;

        // do{
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
            
        // }while(slow!=fast);

        // slow = 0;
        // while(true){
        //     slow = nums[slow];
        //     fast = nums[fast];

        //     if(slow==fast) return slow;
        // }

        //let's try binary search

        int low = 1;
        int high =nums.size()-1;

        while(low<high){
            //avoids integer overflow, finds min
            int mid = low+(high-low)/2;
            
            int count = 0;
            for(int i =0; i<nums.size();i++)
            {
                if(nums[i]<=mid) count++;
            }

            if(count<=mid) low =mid+1;
            else high =mid;

        }
        return low;

        
    }
};