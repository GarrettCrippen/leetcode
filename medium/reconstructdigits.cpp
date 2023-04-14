class Solution
{
public:
    /**
        zero, one, two, three, four, five, six, seven, eight, nine

        seven, nine (v, i)
        one, five (o,f)
        three,four (h,u)
        zero, six, two, eight (z,x,w,g)

    **/
    string originalDigits(string s)
    {
        // store digits here
        vector<char> res;
        // count number;
        unordered_map<char, int> mymap;

        char letters[] = {'z', 'e', 'r', 'o', 'x', 'w', 'g', 'h', 't', 'u', 'f', 'v', 'n', 's'};
        for (char letter : letters)
        {
            mymap[letter] = 0;
        }
        for (int i = 0; i < s.length(); i++)
        {
            mymap[s[i]] += 1;
        }

        bool change = false;
        // zero, six, two, eight (z,x,w,g)
        do
        {
            change = false;
            if (mymap['z'] > 0)
            {
                mymap['z']--;
                mymap['e']--;
                mymap['r']--;
                mymap['o']--;
                res.push_back('0');
                change = true;
            }

            if (mymap['x'] > 0)
            {
                mymap['s']--;
                mymap['i']--;
                mymap['x']--;
                res.push_back('6');
                change = true;
            }

            if (mymap['w'] > 0)
            {
                mymap['t']--;
                mymap['w']--;
                mymap['o']--;
                res.push_back('2');
                change = true;
            }

            if (mymap['g'] > 0)
            {
                mymap['e']--;
                mymap['i']--;
                mymap['g']--;
                mymap['h']--;
                mymap['t']--;
                res.push_back('8');
                change = true;
            }
        } while (change);

        // three,four (h,u)
        do
        {
            change = false;
            if (mymap['h'] > 0)
            {
                mymap['t']--;
                mymap['h']--;
                mymap['r']--;
                mymap['e']--;
                mymap['e']--;
                res.push_back('3');
                change = true;
            }

            if (mymap['u'] > 0)
            {
                mymap['f']--;
                mymap['o']--;
                mymap['u']--;
                mymap['r']--;
                res.push_back('4');
                change = true;
            }
        } while (change);

        // one, five (o,f)
        do
        {
            change = false;
            if (mymap['o'] > 0)
            {
                mymap['o']--;
                mymap['n']--;
                mymap['e']--;
                res.push_back('1');
                change = true;
            }

            if (mymap['f'] > 0)
            {
                mymap['f']--;
                mymap['i']--;
                mymap['v']--;
                mymap['e']--;
                res.push_back('5');
                change = true;
            }
        } while (change);

        // seven, nine (v, i)
        do
        {
            change = false;
            if (mymap['v'] > 0)
            {
                mymap['s']--;
                mymap['e']--;
                mymap['v']--;
                mymap['e']--;
                mymap['n']--;
                res.push_back('7');
                change = true;
            }

            if (mymap['i'] > 0)
            {
                mymap['n']--;
                mymap['i']--;
                mymap['n']--;
                mymap['e']--;
                res.push_back('9');
                change = true;
            }
        } while (change);

        sort(res.begin(), res.end());
        return accumulate(res.begin(), res.end(), std::string());
    }
};