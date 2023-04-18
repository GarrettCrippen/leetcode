// learned splice from stl
// iterator of element you want to insert, list your want to insert it into, and iterator to where you want to remove it
class LRUCache
{
    int capacity;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> my_map;

public:
    LRUCache(int capacity) : capacity{capacity} {}

    int get(int key)
    {
        if (my_map.find(key) == my_map.end())
            return -1;
        lst.splice(lst.begin(), lst, my_map[key]);
        return my_map[key]->second;
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            my_map[key]->second = value;
            return;
        }

        if (my_map.size() == capacity)
        {
            int delKey = lst.back().first;
            lst.pop_back();
            my_map.erase(delKey);
        }

        lst.emplace_front(key, value);
        my_map[key] = lst.begin();
    }
};