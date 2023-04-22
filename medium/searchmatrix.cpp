class Solution
{
public:
    // each row is sorted in non-dec order
    // first int row i > first int row i+1

    // input 2d:matrix
    // output:return t or f

    // let's use binary search twice
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int low = 0, high = matrix.size() - 1, row;

        // find row O(log(m)), e.g. 3
        row = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cout << "mid: " << mid << endl;
            cout << "low: " << low << "high: " << high << endl;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
            {
                high = mid - 1;
            }
            else
            {
                row = mid;
                low = mid + 1;
            }
            // cout<<"mid is: "<<mid<<endl;
        }
        cout << "row is: " << row << endl;
        // we found the row, now find the col if it exists
        low = 0, high = matrix[0].size() - 1;
        cout << "BEFORE   LOW: " << low << ", HIGH: " << high << endl;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cout << "val" << matrix[row][mid] << endl;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
            {
                high = mid - 1;
            }
            else
            {

                low = mid + 1;
                cout << "LOW: " << low << ", HIGH: " << high << endl;
            }
        }
        return false;
    }
};