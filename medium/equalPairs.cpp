class Solution
{
public:
    // at most max(i,j) pairs st. r_i == c_j
    // at least 0 pairs

    // idea mantain map of column and rows
    // additional i+j space
    int equalPairs(vector<vector<int>> &grid)
    {
        // mantain two unordered_maps and check!, key is frequency

        // we can try to use unordered map, but it requires hash function
        map<vector<int>, int> ri;
        map<vector<int>, int> cj;

        // do for rows
        for (int r = 0; r < grid.size(); r++)
        {
            vector<int> row;
            for (int c = 0; c < grid[0].size(); c++)
            {
                row.push_back(grid[r][c]);
            }
            if (ri.count(row) > 0)
                ri[row]++;
            else
                ri[row] = 1;
        }

        // do same for cols
        for (int c = 0; c < grid[0].size(); c++)
        {
            vector<int> col;
            for (int r = 0; r < grid.size(); r++)
            {
                col.push_back(grid[r][c]);
            }
            if (cj.count(col) > 0)
                cj[col]++;
            else
                cj[col] = 1;
        }

        int res = 0;
        for (auto it = ri.begin(); it != ri.end(); it++)
        {

            // check if ri exists in cj
            if (cj.count(it->first))
                res += cj[it->first] * it->second;
        }

        return res;
    }
};