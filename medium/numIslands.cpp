class Solution
{
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    // let's use some sort of flood fill algorithm (BFS)
    int numIslands(vector<vector<char>> &grid)
    {
        // visited array
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        // iterate through and if not visited then run flood fill algorithm and add count
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                // run algorithm
                if (!visited[r][c] && grid[r][c] == '1')
                {

                    stack<pair<int, int>> st;
                    st.push({r, c});
                    while (!st.empty())
                    {
                        pair<int, int> temp = st.top();
                        st.pop();
                        visited[temp.first][temp.second] = true;

                        for (int i = 0; i < 4; i++)
                        {
                            int newRow = temp.first + dx[i];
                            int newCol = temp.second + dy[i];

                            // bounds check
                            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || visited[newRow][newCol])
                                continue;

                            if (grid[newRow][newCol] == '1')
                            {
                                st.push({newRow, newCol});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};