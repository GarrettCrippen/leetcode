class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 3 == 0 and (i + 1) % 5 == 0)
            {
                a[i] = "FizzBuzz";
            }
            else if ((i + 1) % 3 == 0)
            {
                a[i] = "Fizz";
            }
            else if ((i + 1) % 5 == 0)
            {
                a[i] = "Buzz";
            }
            else
            {
                a[i] = to_string((i + 1));
            }
        }
        return a;
    }
};