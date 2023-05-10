class Solution
{
public:
    // 0 empty, 1 fresh, 2 orange
    // input: matrix
    // output: number of minutes or -1

    // this is possible iff every orange is reachable by a fresh orange
    // every orange check if its neighbor is rotten, then update

    int orangesRotting(vector<vector<int>> &grid)
    {

        vector<pair<int, int>> v;
        // push all fresh oranges onto a queue
        for (int i = 0; i < grid.size(); i++)
        {

            for (int k = 0; k < grid[0].size(); k++)
            {

                if (grid[i][k] == 1)
                {
                    v.push_back({i, k});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int minutes = 0;
        while (!v.empty())
        {

            queue<pair<int, int>> update;
            for (auto it = v.begin(); it != v.end(); it++)
            {
                pair<int, int> temp = *it;

                for (int i = 0; i < 4; i++)
                {
                    int new_x = dx[i] + temp.first;
                    int new_y = dy[i] + temp.second;

                    // bounds check here
                    if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size())
                        continue;

                    // remove if it is erased and remember to change to rotten after
                    if (grid[new_x][new_y] == 2)
                    {
                        update.push(temp);
                        v.erase(it);
                        it--;
                        break;
                    }
                }
            }

            // this means that we could not turn a fresh orange into rotten
            if (update.empty())
                return -1;

            minutes++;
            // now we can update the oranges as rotten after visiting all
            while (!update.empty())
            {
                pair<int, int> temp = update.front();
                update.pop();

                grid[temp.first][temp.second] = 2;
            }
        }

        return minutes;
    }
};