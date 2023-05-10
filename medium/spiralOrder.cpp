class Solution
{
public:
    // Idea move a single direction: dx or dy

    // mantain visited array (might be possible with O(1) space)
    // Algorithm: keep going right, down, left up
    //{1,0}, {0,-1}, {-1,0},{0,1}. untill all cells are visited
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        // current cell
        int r = 0, c = 0;
        // current direction
        int i = 0;
        // if we change directions instantly then end
        bool once = false;

        vector<int> res;
        res.push_back(matrix[0][0]);
        visited[0][0] = true;
        while (true)
        {
            // set as visited

            int new_r = r + dy[i];
            int new_c = c + dx[i];
            // cout<<"r: "<<r<<", c: "<<c<<endl;
            // cout<<"new_r: "<<new_r<<", new_c: "<<new_c<<endl;
            // cout<<"i: "<<i<<endl;

            // if we meet border or already visited then continue
            if (new_r < 0 || new_r >= matrix.size() || new_c < 0 || new_c >= matrix[0].size() || visited[new_r][new_c])
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
                res.push_back(matrix[new_r][new_c]);
                visited[new_r][new_c] = true;
                r = new_r;
                c = new_c;
            }
        }

        return res;
    }
};