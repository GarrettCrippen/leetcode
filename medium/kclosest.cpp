struct cmp
{
    bool operator()(const pair<double, vector<int>> o, const pair<double, vector<int>> t)
    {
        return o.first > t.first;
    }
};

class Solution
{
public:
    // return k closest points to origin, i.e. distance is minimal to origin

    // let's use a priority queue and sort by greater<int>

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, cmp> pq;

        for (auto it = points.begin(); it != points.end(); it++)
        {
            double distance = sqrt(pow((*it)[0], 2) + pow((*it)[1], 2));
            pq.push({distance, *it});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};