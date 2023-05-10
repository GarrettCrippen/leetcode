class Solution
{
public:
    // 1) sort by starting intervals
    // 2) keep track of current 'index'
    //    a) end of current index < start of next index => push
    //    b) else keep updating current index
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [&](const auto f, const auto s)
             { return f[0] < s[0]; });

        if (intervals.size() == 1)
            return intervals;

        vector<int> myInterval = *intervals.begin();
        // cout<<myInterval[0]<<","<<myInterval[1]<<endl;
        for (auto it = intervals.begin() + 1; it != intervals.end(); it++)
        {

            if ((*it)[0] > myInterval[1])
            {
                res.push_back(myInterval);
                myInterval = *it;
            }
            else
            {
                myInterval[1] = max(myInterval[1], (*it)[1]);
            }
            if (next(it) == intervals.end())
                res.push_back(myInterval);
        }

        return res;
    }
};