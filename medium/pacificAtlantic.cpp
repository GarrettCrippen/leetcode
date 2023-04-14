#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> res;
        if (heights.empty())
            return res;

        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));

        // DFS search from the border cells

        //check left and right
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        //check top and bottom
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        // check if a cell is reachable from both oceans
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.emplace_back(vector<int>{i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j)
    {
        ocean[i][j] = true;
        int m = heights.size(), n = heights[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !ocean[x][y] && heights[x][y] >= heights[i][j])
            {
                dfs(heights, ocean, x, y);
            }
        }
    }
};