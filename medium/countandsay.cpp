#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        // iterate and if it changes or then ends, then append string
        //(right to left is cheaper)

        int last = n % 10;
        int rem = n / 10;

        string s = "";
        int count = 1;
        while (rem)
        {
            int prev = last;
            last = rem % 10;
            rem = rem / 10;
            if (last == prev)
            {
                count++;
                if (rem == 0)
                {
                    s.insert(0, to_string(count) + to_string(prev));
                }
            }
            else
            {
                // prepend
                s.insert(0, to_string(count) + to_string(prev));
                int count = 1;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(3322251) << endl;
    return 0;
}