class Solution
{
public:
    // Palidromes are symmetric:
    // even number of letters except for the middle letter can be odd.
    // Solution: mantain a map and iterate through the string in one pass.
    //     int longestPalindrome(string s) {
    //         map<char,int>myMap;

    //         int count =0;
    //         //count number of letters
    //         for(auto it = s.begin(); it!=s.end(); it++){
    //             //double letters = +2 count
    //             if(myMap.count(*it)>0){
    //                 myMap.erase(*it);
    //                 count+=2;
    //             }
    //             else{
    //                 myMap[*it]=1;
    //             }
    //         }
    //         if(myMap.size()){
    //             return count+1;
    //         }
    //         else{
    //             return count;
    //         }

    //     }
    // };

    // Optimize to not erase every time we find duplicate
    class Solution
    {
    public:
        // Palidromes are symmetric:
        // even number of letters except for the middle letter can be odd.
        // Solution: mantain a map and iterate through the string in one pass.
        int longestPalindrome(string s)
        {
            unordered_map<char, int> myMap;

            int count = 0;
            // count number of letters
            for (auto it = s.begin(); it != s.end(); it++)
            {
                // double letters = +2 count
                if (myMap.count(*it) > 0)
                {
                    myMap[*it]++;
                    if (myMap[*it] % 2 == 0)
                    {
                        count += 2;
                    }
                }
                else
                {
                    myMap[*it] = 1;
                }
            }
            for (auto it = myMap.begin(); it != myMap.end(); it++)
            {
                if (it->second % 2 == 1)
                {
                    return count + 1;
                }
            }
            return count;
        }
    };