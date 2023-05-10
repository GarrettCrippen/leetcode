class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {

        //[r+1][j+1]

        int sum = 0;
        int r = 0, j = 0;

        while (r < mat.size())
        {
            sum += mat[r][j];
            r++;
            j++;
        }

        r = 0;
        j = mat[0].size() - 1;
        while (r < mat.size())
        {
            sum += mat[r][j];
            r++;
            j--;
        }

        if (mat[0].size() % 2 == 1)
            sum -= mat[mat.size() / 2][mat.size() / 2];

        return sum;
    }
};