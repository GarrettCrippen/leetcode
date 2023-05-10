class Solution
{
public:
    // sort and iterate through
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        //,[](vector<int>f,vector<int>s){            f.first < s.first;}
        sort(intervals.begin(), intervals.end());

        auto curInt = *intervals.begin();
        int count = 0;
        // cout<<curInt[0]<<","<<curInt[1]<<endl;
        for (auto it = intervals.begin() + 1; it != intervals.end(); it++)
        {
            // cout<<(*it)[0]<<","<<(*it)[1]<<endl;
            // if it.second >= curInt.second then we can continue
            if (curInt[1] <= (*it)[0])
            {
                curInt = *it;
                continue;
            }
            else
            {
                count++;
                if (curInt[1] > (*it)[1])
                    curInt = *it;
            }
        }
        return count;
    }
};