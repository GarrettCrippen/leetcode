class Solution
{
public:
    // find smallest k (bananas per hour) or piles[i]
    // finish bananas within h hours

    // let's use binary search:
    // min: homogenous, min(piles)
    // max: hetereogeneous max(piles)

    // Note: h is lte piles.length, so it is always possible
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        int mid, res = high;
        // takes O(nlogn) time.
        sort(piles.begin(), piles.end());

        long my_h = 0;
        // do binary search here
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            my_h = 0;
            // cout<<"mid val is: "<<mid<<endl;
            for (auto it = piles.begin(); it != piles.end(); it++)
            {
                // Need to find ceil here
                int floor = *it / mid;
                int rem = *it % mid;
                floor += rem ? 1 : 0;
                my_h += floor;
                // integer overflow, try another way
                //  my_h+=((*it)+mid-1)/mid;
            }
            // cout<<"h is: "<<my_h<<endl;
            // want to find the smaller and smaller k
            if (my_h <= h)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};