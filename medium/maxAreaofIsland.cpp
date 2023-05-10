class Solution
{
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    // use dfs floodfill algorithm and keep track of number of land
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        stack<pair<int, int>> st;

        int myMax = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (!visited[r][c] && grid[r][c] == 1)
                {
                    int count = 1;
                    st.push({r, c});
                    visited[r][c] = true;
                    while (!st.empty())
                    {
                        pair<int, int> temp = st.top();
                        st.pop();

                        for (int i = 0; i < 4; i++)
                        {
                            int new_x = temp.first + dx[i];
                            int new_y = temp.second + dy[i];

                            // bounds check here
                            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size() || visited[new_x][new_y])
                                continue;

                            if (grid[new_x][new_y] == 1)
                            {
                                st.push({new_x, new_y});
                                visited[new_x][new_y] = true;
                                count++;
                            }
                        }
                    }
                    myMax = max(count, myMax);
                }
            }
        }

        return myMax;
    }
};