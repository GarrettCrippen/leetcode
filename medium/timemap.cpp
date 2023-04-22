
// store multiple values of the same key at different time stamps

// pair<key,timestamp>
class TimeMap
{
    // let's figure out what data structures to use
    // alphnumeric
    // timestamp is non decreasing
private:
    // key, pair<timestamp,value>
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    // sets largest[key,timestamp] = value
    // note all values are strictly increasing!
    void set(string key, string value, int timestamp)
    {
        m[key].emplace_back(make_pair(timestamp, value));
    }
    // 12 3 4 5 6
    // gets largest[key,timestamp] <= value(timestamp)
    // or ""
    string get(string key, int timestamp)
    {
        // no key associated
        if (m.count(key) == 0)
        {
            return "";
        }

        int low = 0, high = m[key].size() - 1;
        vector<pair<int, string>> *curr = &m[key];
        int mid, res = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (((*curr)[mid]).first == timestamp)
            {
                return ((*curr)[mid]).second;
            }
            // too big -> check left
            if (((*curr)[mid]).first > timestamp)
            {
                high = mid - 1;
            }
            // too small -> check right
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
        if (res != -1)
            return ((*curr)[res]).second;

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */