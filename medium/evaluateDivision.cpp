#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        unordered_map<string, unordered_map<string, double>> mp;
        vector<double> res;

        for (int i = 0; i < equations.size(); i++)
        {
            vector<string> temp = equations[i];
            mp[temp[0]][temp[1]] = values[i];
            mp[temp[1]][temp[0]] = (1.0 / values[i]);
        }

        for (int i = 0; i < queries.size(); i++)
        {

            vector<string> temp = queries[i];
            if (mp.count(temp[0]))
            {
                unordered_map<string, double> visited;
                double result = search(temp[0], temp[1], mp, visited);
                res.push_back(result);
            }
            else
            {
                res.push_back(-1.0);
            }
        }

        return res;
    }

private:
    double search(const string &start, const string &end, unordered_map<string, unordered_map<string, double>> &mp, unordered_map<string, double> &visited)
    {
        if (start == end)
        {
            return 1.0;
        }

        if (visited.count(start))
        {
            return -1.0; // Cycle detected, cannot infer value
        }

        visited[start] = 1.0;

        for (const auto &neighbor : mp[start])
        {
            string next = neighbor.first;
            double value = neighbor.second;

            // keeps searching as long as there is an existing edge
            double subResult = search(next, end, mp, visited);
            if (subResult != -1.0)
            {
                return value * subResult;
            }
        }

        return -1.0;
    }
};