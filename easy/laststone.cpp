class Solution
{
private:
    priority_queue<int, vector<int>, less<int>> pq;

public:
    // pick two largest stones
    // both are destroyed or smaller taken away from larger

    // input: list of stones
    // output size of largest stone
    int lastStoneWeight(vector<int> &stones)
    {
        for (auto it = stones.begin(); it != stones.end(); it++)
        {
            pq.push(*it);
        }

        while (!pq.empty())
        {
            int first = pq.top();
            pq.pop();

            // do not continue if only 1 stone
            if (pq.empty())
                return first;

            int second = pq.top();
            pq.pop();

            cout << "FIRST" << first << endl;
            cout << "SECOND" << second << endl;
            cout << "-------------" << endl;

            // push the difference
            if (first != second)
                pq.push(abs(first - second));
        }
        return 0;
    }
};