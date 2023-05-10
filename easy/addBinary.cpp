class Solution
{
public:
    string addBinary(string a, string b)
    {

        // a is shorter
        if (a.length() > b.length())
            return addBinary(b, a);

        string res = "";
        bool carry = false;
        const int diff = b.length() - a.length();
        // go right to left
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int cnt = 0;
            if (carry)
            {
                cnt++;
                carry = false;
            }
            if (a[i] == '1')
                cnt++;
            if (b[i + diff] == '1')
                cnt++;

            if (cnt >= 2)
            {
                cnt %= 2;
                carry = true;
            }
            // concatenate
            res.insert(0, 1, cnt + '0');
        }

        for (int i = diff - 1; i >= 0; i--)
        {
            int cnt = 0;
            if (carry)
            {
                cnt++;
                carry = false;
            }

            if (b[i] == '1')
                cnt++;

            if (cnt >= 2)
            {
                cnt %= 2;
                carry = true;
            }
            // concatenate
            res.insert(0, 1, cnt + '0');
        }
        if (carry)
            res.insert(0, 1, '1');

        return res;
    }
};