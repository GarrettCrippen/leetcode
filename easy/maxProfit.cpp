class Solution
{
public:
    // Note: only care about set that is strictly increasing
    // Trivial solution: brute force n^2 combinations
    int maxProfit(vector<int> &prices)
    {
        int my_max = 0;
        // for(int i = 0; i<prices.size()-1;i++){
        //     for(int k = i+1; k<prices.size(); k++){
        //         my_max = max(my_max,(prices[k]-prices[i]));
        //     }
        // }

        // Let's try to go backwards and skip where k < my_max, so we can just continue

        for (int k = prices.size() - 1; k > 0; k--)
        {
            if (prices[k] <= my_max)
            {
                continue;
            }
            for (int i = k - 1; i >= 0; i--)
            {
                my_max = max(my_max, (prices[k] - prices[i]));
            }
        }

        return my_max;
    }
};