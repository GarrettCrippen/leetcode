// sort largest to greatest -> return k

// data type to use is a list, for easy insertion
// store iterator to k
class KthLargest
{
private:
    list<int> myList;
    int kth;
    list<int>::iterator my_k = myList.end();

public:
    KthLargest(int k, vector<int> &nums)
    {
        // sort by greater -> less than
        sort(nums.begin(), nums.end(), greater<int>());
        kth = k;

        // nothing to do here
        if (nums.empty())
            return;

        // intialize linked list
        myList.assign(nums.begin(), nums.end());
        my_k = myList.begin();
        std::advance(my_k, k - 1);
    }

    int add(int val)
    {

        // base case
        if (myList.empty())
        {
            myList.insert(myList.begin(), val);
            my_k = myList.begin();
            return *my_k;
        }

        // doesn't matter if LTE
        if (val < *my_k)
        {
            cout << "case 2" << endl;

            cout << "val = " << val << endl;
            if (kth > myList.size())
                return val;
            return *my_k;
        }

        for (auto it = myList.begin(); it != myList.end(); it++)
        {
            if (val >= *it)
            {
                cout << "INSERTING" << val << "before" << *it << endl;
                myList.insert(it, val);
                cout << "inserting" << *it << endl;
                my_k--;
                break;
            }
        }

        return *my_k;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */