class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

public:
    // idea for every o, we can just set neighbor as not surrounded
    // then surrounded[][]==true of board set to x

    // traverse the edge 'o's with dfs and mark as visited
    // every other o fill in
    void solve(vector<vector<char>> &board)
    {
        set<pair<int, int>> traverse;

        // add all col where row = 0 etc
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[0][i] == 'O')
                traverse.insert({0, i});
            if (board[board.size() - 1][i] == 'O')
                traverse.insert({board.size() - 1, i});
        }

        // add all rows where col = 0 etc
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
                traverse.insert({i, 0});
            if (board[i][board[0].size() - 1] == 'O')
                traverse.insert({i, board[0].size() - 1});
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<bool>> surrounded(board.size(), vector<bool>(board[0].size(), true));
        stack<pair<int, int>> st;
        for (auto it = traverse.begin(); it != traverse.end(); it++)
        {
            st.push(*it);
        }

        // traverse visit all o's that are not surrounded!
        while (!st.empty())
        {
            pair<int, int> temp = st.top();
            st.pop();

            surrounded[temp.first][temp.second] = false;
            visited[temp.first][temp.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int new_x = temp.first + dx[i];
                int new_y = temp.second + dy[i];

                if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size() || visited[new_x][new_y])
                    continue;

                if (board[new_x][new_y] == 'O')
                    st.push({new_x, new_y});
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int k = 0; k < board[0].size(); k++)
            {
                if (!visited[i][k] && board[i][k] == 'O')
                {
                    board[i][k] = 'X';
                    visited[i][k] = true;
                }
            }
        }
    }
};