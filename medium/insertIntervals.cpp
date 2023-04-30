class Solution
{
public:
    // input: vector of intervals, and interval that we want to insert
    // output: vector of intervals #insert/merge the interval

    // intution: binary search to find iterval before this one and decide to merge or not merge
    // i.e. int.[first] < newInterval.first
    //  and int.[second]>newInterval.first
    // there can be multiple intervals
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        // check if start of end of new interval is lt start of next interval

        vector<vector<int>> res;
        vector<int> myInterval = newInterval;
        bool inserted = false;

        for (auto it = intervals.begin(); it != intervals.end(); it++)
        {
            // my interval is before the next interval
            if (!inserted && newInterval[1] < (*it)[0])
            {
                // cout<<"first"<<endl;
                res.push_back(myInterval);
                res.push_back(*it);
                inserted = true;
            }
            // else its after next interval
            else if (inserted || newInterval[0] > (*it)[1])
            {
                // cout<<"sec"<<endl;
                res.push_back(*it);
                if (!inserted && next(it) == intervals.end())
                    res.push_back(myInterval);
            }
            else
            {
                // cout<<"third"<<endl;
                myInterval[0] = min((*it)[0], myInterval[0]);
                myInterval[1] = max((*it)[1], myInterval[1]);
                cout << (*it)[0] << "," << (*it)[1] << endl;
                if (next(it) == intervals.end())
                    res.push_back(myInterval);
            }
        }
        if (res.empty())
            res.push_back(newInterval);
        return res;
    }
};