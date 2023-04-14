#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int numDecodings(std::string s)
    {
        std::unordered_map<std::string, int> memo;
        return recurse(s, memo);
    }

    int recurse(std::string s, std::unordered_map<std::string, int> &memo)
    {
        if (s.length() == 0)
        {
            return 1;
        }
        else if (s.length() == 1)
        {
            int num = stoi(s);
            if (num >= 1 && num <= 9)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (memo.count(s))
        {
            return memo[s];
        }

        int count = 0;

        int num = stoi(s.substr(0, 1));
        if (num >= 1 && num <= 9)
        {
            count += recurse(s.substr(1), memo);
        }
        else
        {
            memo[s] = count;
            return count;
        }

        num = stoi(s.substr(0, 2));
        if (num >= 10 && num <= 26)
        {
            count += recurse(s.substr(2), memo);
        }

        memo[s] = count;
        return count;
    }
};

int main()
{
    Solution my_solution;
    std::string test = "12";
    std::cout << my_solution.numDecodings(test) << std::endl;
    return 0;
}