class Solution
{
public:
    // input: char array
    // output: int time

    // note each task done in 1 unit of time
    // n cooldown between same tasks eg. A and A

    // A to Z
    int leastInterval(vector<char> &tasks, int n)
    {
        // push l unique types onto pq and update priority after popping

        unordered_map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (mp.count(tasks[i]) > 0)
                mp[tasks[i]]++;
            else
                mp[tasks[i]] = 1;
        }

        // max heap
        priority_queue<int, vector<int>, less<int>> pq;
        queue<pair<int, int>> q;

        // push frequncies on
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push(it->second);
        }

        int time = 0;
        // idea: use most frequent and legal task
        while (!pq.empty() || !q.empty())
        {
            time++;
            if (!pq.empty())
            {
                cout << "PQ " << pq.top() << endl;
                // decrement task and push onto queue
                int temp = pq.top();
                pq.pop();

                // see if we are done with the current task

                if (temp - 1 > 0)
                    q.push({temp - 1, time + n});
            }
            // pop from q and add back to max_heap
            if (!q.empty() && q.front().second <= time)
            {

                cout << "Q " << q.front().first << "," << q.front().second << endl;

                // see if we are done with the current task
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};