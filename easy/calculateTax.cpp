class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double aval = income, res = 0.0;

        for (int i = 0; i < brackets.size(); i++)
        {

            if (aval == 0)
                return res;

            if (i == 0)
            {
                if (aval >= brackets[i][0])
                {
                    res += (double)brackets[i][0] * (brackets[i][1] / 100.0);
                    aval -= brackets[i][0];
                }
                else
                {
                    res += (double)aval * (brackets[i][1] / 100.0);
                    aval = 0;
                }
            }
            // see if we have enough balance to meet current tax bracket
            else if (aval >= brackets[i][0] - brackets[i - 1][0])
            {
                res += (double)(brackets[i][0] - brackets[i - 1][0]) * (brackets[i][1] / 100.0);
                aval -= brackets[i][0] - brackets[i - 1][0];
            }
            // else use current balance;
            else
            {
                res += (double)(aval) * (brackets[i][1] / 100.0);
                aval = 0;
            }
        }

        return res;
    }
};