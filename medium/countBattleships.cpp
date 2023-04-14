class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Important that there is 1 cell vertical or horizontally seperating them
    int countBattleships(vector<vector<char>> &board)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        int count = 0;
        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                if (!visited[r][c] and board[r][c] == 'X')
                {
                    // cout<<"VISITING: "<<r<<","<<c<<endl;
                    dfs(visited, board, r, c);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<bool>> &visited, vector<vector<char>> &board, int x, int y)
    {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;

            // check to see if we go out of bounds
            if (new_x < 0 or new_x >= board.size() or new_y < 0 or new_y >= board[0].size())
            {
                continue;
            }

            // visit the rest of the battle ship
            if (!visited[new_x][new_y] and board[new_x][new_y] == 'X')
            {
                // cout<<"NOW VISITING CONNECTED:"<<new_x<<","<<new_y<<endl;
                dfs(visited, board, new_x, new_y);
            }
        }
    }
};