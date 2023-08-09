class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        // current cell
        int r = 0, c = 0;
        // current direction
        int i = 0;
        // if we change directions instantly then end
        bool once = false;

        int cnt = 2;
        visited[0][0] = true;
        while (true)
        {
            // set as visited

            int new_r = r + dy[i];
            int new_c = c + dx[i];

            // if we meet border or already visited then continue
            if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n || visited[new_r][new_c])
            {

                if (once)
                    break;

                i++;
                i %= 4;
                once = true;
            }
            else
            {
                once = false;
                res[new_r][new_c] = cnt++;
                visited[new_r][new_c] = true;
                r = new_r;
                c = new_c;
            }
        }

        return res;
    }
};