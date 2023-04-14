#include <iostream>
#include <string>
#include <map>
#include <numeric>

using namespace std;

map<pair<string, string>, int> mymap;
int deletionDistance(const string &str1, const string &str2)
{
    // let's just think of some edge cases
    if (str1.length() == 0)
    {
        return str2.length();
    }
    else if (str2.length() == 0)
    {
        return str1.length();
    }

    // dynamic programming
    if (mymap.count({str1, str2}) > 0)
    {
        return mymap[{str1, str2}];
    }

    // recursive solution
    // last char in both are the same, so just pass the prefix
    if (str1[str1.length() - 1] == str2[str2.length() - 1])
    {
        mymap[{str1, str2}] = deletionDistance(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1));
        return mymap[{str1, str2}];
    }
    else //  last char in both are different, so recurse on min(removing one and add 1)
    {
        // recurse on prefix of both
        mymap[{str1, str2}] = min(deletionDistance(str1.substr(0, str1.length() - 1), str2) + 1,
                                  deletionDistance(str1, str2.substr(0, str2.length() - 1)) + 1);
        return mymap[{str1, str2}];
    }
}

int main()
{
    cout << deletionDistance("dog", "frog") << endl;
    cout << deletionDistance("some", "some") << endl;
    cout << deletionDistance("some", "thing") << endl;

    return 0;
}