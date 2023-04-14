class Solution
{
public:
    // assume num1 is either the same size or longer than num2
    string addStrings(string num1, string num2)
    {
        if (num2.size() > num1.size())
        {
            return addStrings(num2, num1);
        }

        // idea convert individual digit to int and add
        bool carry = false;
        int d1gits = 0;
        int d2gits = 0;

        int s2 = num2.size() - 1;
        string myString = "";
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            d1gits = num1[i] - 48;
            d2gits = 0;
            if (s2 >= 0)
            {
                d2gits = num2[s2] - 48;
                s2--;
            }
            // compute sum and if we need to cary
            int sum = d1gits + d2gits + (carry ? 1 : 0);
            if (sum >= 10)
            {
                sum -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }
            char toAdd = char(sum + 48);
            myString.insert(0, 1, toAdd);
        }
        if (carry)
        {
            myString.insert(0, 1, '1');
        }
        return myString;
    }
};