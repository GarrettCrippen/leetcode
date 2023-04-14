class Solution
{
public:
    // rows and cols are groups of 3

    // can iterate rows in n*m time
    // can iterate cols in m*n time
    // simultaneously: track digits for each of the nine grids

    // input: 2d vector of 1..9 or '.'
    // output: T or F
    bool isValidSudoku(vector<vector<char>> &board)
    {

        vector<unordered_map<char, int>> my_rows(9);
        vector<unordered_map<char, int>> my_cols(9);
        vector<unordered_map<char, int>> grids(9);

        // iterate rows and check if valid
        for (int i = 0; i < board.size(); i++)
        {

            // check for duplicates in rows,cols,grids
            for (int k = 0; k < board.size(); k++)
            {
                int grid_index = (i / 3) * 3 + k / 3;
                if ((my_rows[i].count(board[i][k])) > 0)
                {
                    // cout<<"DUPE IN ROW: val = "<<board[i][k]<<endl;
                    return false;
                }
                if ((my_cols[k].count(board[i][k])) > 0)
                {
                    //  cout<<"DUPE IN COL: "<<k<<"VAL = "<<board[k][i]<<endl;
                    return false;
                }
                if (grids[grid_index].count(board[i][k]) > 0)
                {
                    // cout << "DUPLICATE IN GRID:" << grid_index << endl;
                    return false;
                }

                if (isdigit(board[i][k]))
                {
                    my_rows[i][board[i][k]] = 1;
                    my_cols[k][board[i][k]] = 1;
                    grids[grid_index][board[i][k]] = 1;
                }
            }
        }

        return true;
    }
};