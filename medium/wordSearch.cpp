class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

public:
    // input:2d vector
    // output:t/f if word exists
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // let's recurse only on starting letter
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (recurse(board, word, visited, i, j, 1))
                    {
                        return true;
                    }
                    // pseudo backtracking
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool recurse(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int x, int y, int idx)
    {
        if (idx == word.length())
        {
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            // bounds checking
            if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size() || visited[new_x][new_y])
                continue;

            // navigate
            if (board[new_x][new_y] == word[idx])
            {
                visited[new_x][new_y] = true;
                if (recurse(board, word, visited, new_x, new_y, idx + 1))
                {
                    return true;
                }
                visited[new_x][new_y] = false;
            }
        }
        return false;
    }
};
