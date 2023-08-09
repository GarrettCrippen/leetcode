class Solution
{
public:
    // first and last numbers are always one except first level
    // each level increases by 1
    //  add group of twos

    // constraint size is atleast one
    vector<vector<int>> generate(int numRows)
    {
        // base case for levels 0 and 1

        vector<vector<int>> res;

        res.push_back(vector<int>{1});
        if (numRows == 1)
        {
            return res;
        }
        res.push_back(vector<int>{1, 1});
        if (numRows == 2)
        {
            return res;
        }

        // i represents numbers in current row
        for (int i = 2; i < numRows; i++)
        {

            // start
            vector<int> temp = {1};
            int j = 1;
            while (j < i)
            {
                // cout<<"adding: "<<res[i-1][j-1]+res[i-1][j]<<endl;
                temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                j++;
            }
            temp.push_back(1);
            res.push_back(temp);
        }

        return res;
    }
};