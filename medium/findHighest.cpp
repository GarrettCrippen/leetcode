class Solution
{
public:
    // trivial to use n extra memory
    // instead try to use constant memory
    int largestAltitude(vector<int> &gain)
    {
        int my_max = 0, cur = 0;

        for (int &e : gain)
        {

            cur += e;
            my_max = max(my_max, cur);
        }

        return my_max;
    }
};