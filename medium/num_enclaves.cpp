#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // run a dfs to the boundaries, similar to pacific atlantic-problem, but less strict.
    // no elevation required.

    // difference is that we want to find the land that cannot access the boundaries.
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<bool>> accessible(grid.size(), vector<bool>(grid[0].size(), false));

        // up down boundaries
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (grid[0][i])
                dfs(grid, accessible, 0, i);
            if (grid[grid.size() - 1][i])
                dfs(grid, accessible, grid.size() - 1, i);
        }

        // left right boundaries
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0])
                dfs(grid, accessible, i, 0);
            if (grid[i][grid[0].size() - 1])
                dfs(grid, accessible, i, grid[0].size() - 1);
        }

        // want to find intersection (not accessible and grid)
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (not accessible[i][k] and grid[i][k])
                {
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &accessible, int r, int c)
    {
        accessible[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int new_r = r + dx[i];
            int new_c = c + dy[i];

            if (new_r < 0 or new_r >= grid.size() or new_c < 0 or new_c >= grid[0].size())
                continue;

            // check for bounds
            if (grid[new_r][new_c] and not accessible[new_r][new_c])
            {
                cout << "recursing" << endl;
                dfs(grid, accessible, new_r, new_c);
            }
        }
    }
};

int main()
{

    Solution s = Solution();
    // vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    vector<vector<int>> grid = {{0, 1, 1, 0},
                                {0, 0, 1, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 0}};
    cout
        << s.numEnclaves(grid) << endl;
    return 0;
}