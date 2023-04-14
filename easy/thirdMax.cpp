class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //create set from gt to lt
        set<int,greater<int>> mySet;
        for(int x: nums){
            mySet.insert(x);
        }

        auto it = mySet.begin();
        if(mySet.size()>=3)
            advance(it,2);
    
        return *it;

    }
};