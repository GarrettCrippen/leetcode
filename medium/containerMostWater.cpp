class Solution
{
public:
    // calculation: min(height(i),height(k))*(k-i)
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int myMax = 0;

        // we can be greedy and move pointer that has smaller height by one
        while (l < r)
        {

            int h = min(height[l], height[r]);
            int water = h * (r - l);
            myMax = max(myMax, water);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return myMax;
    }
};