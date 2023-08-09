class Solution {
public:


    // //we want the largest of smallest values of pairs

    // //greedy idea: use data structure, pop indexes if duplicate value exists
    //     //X doesn't work: if p > number of duplicates
    //     //otherwise: pop closest value on data structure
    //     //note we don't care about indices -> use unordered set

    // //p is smaller or equal to than number of nums

    // int minimizeMax(vector<int>& nums, int p) {

    //     //base case
    //     if(!p) return 0;

    //     //maximum of empty set is zero
    //     int myMin = INT_MAX;

    //     unordered_map<int,int> myS;

    //     //increment count by 1
    //     for(auto & i : nums){
    //         myS[i]++;
    //     }

    //     //keep removing duplicates
    //     unordered_map<int,int>::iterator it = myS.begin();
    //     while(p && it != myS.end()){

    //         //not a duplicate          
    //         if(it->second <=1 ){
    //             it++;
    //             continue;
    //         }
    //         //a duplicate
    //         it->second -= 2;
    //         p--;
    //         if(it->second == 0){
    //             cout<<"removing "<<it->first<<endl;
    //             it = myS.erase(it);
    //         }
    //     }

    //         while(p){
    //             //find min distance for each num and then find the min of mins
    //             unordered_map<int,int>::iterator it1,it2;
    //             it1=myS.end(); 
    //             it2=myS.end();
    //             for(auto my_it = myS.begin(); my_it!= myS.end(); my_it++){
                    
    //                 for(auto my_it2 = myS.begin(); my_it2!= myS.end(); my_it2++){
                    
    //                     if(my_it == my_it2)continue;
    //                     int temp = abs(my_it->first - my_it2->first);
    //                     if(temp < myMin){
    //                         it1 = my_it;
    //                         it2 = my_it2;
    //                         myMin = temp;
    //                     }

    //                 }
    //             }

    //             if(it1 != myS.end()){
    //                 cout<<"erasing"<<it1->first<<endl;
    //                 myS.erase(it1);}

    //             if(it2 != myS.end()){
    //                 cout<<"erasing"<<it2->first<<endl;
    //                 myS.erase(it2);}
    //             p--;          
    //     }
    // cout<< myMin<<endl;
    // cout<< INT_MAX<<endl;
    // return myMin == INT_MAX ? 0 : myMin;
    // }

    //binary search: start with highest possible size and then lower search space
   //able to  find p pairs with maximum difference of mid or not
    bool solve(vector<int>& nums,int d,int p){
        int n=nums.size();
        int c=0;
         for (int i = 0; i  < n-1; i++){

            if (nums[i + 1] - nums[i] <= d) {
               c++;
               i++;//no index appears more than once amongst the p pairs
            }
            if(c>=p)//able to find
            return true;
           }
           return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
    //maximum difference is maximum element - minimum element
        int lo = 0, hi = nums[n-1] - nums[0];
    //we are checking for all the difference by binary search instead of linear search
        while (lo < hi) {
            int mid = (lo + hi) / 2;
        
            //if we can solve with mid, then check left, otherwise check right
            if (solve(nums,mid,p))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
