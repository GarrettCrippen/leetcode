class Solution
{
public:
    // push all on to stack, if we don't empty stack then it fails
    //  { { { } } }
    //  { (})
    //  {}{}
    bool isValid(string s)
    {
        stack<char> st;

        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == '(' or *it == '[' or *it == '{')
                st.push(*it);
            else if (!st.empty())
            {
                if (*it == ')')
                {
                    if (st.top() != '(')
                        return false;
                    st.pop();
                }
                else if (*it == '}')
                {
                    if (st.top() != '{')
                        return false;
                    st.pop();
                }
                else if (*it == ']')
                {
                    if (st.top() != '[')
                        return false;
                    st.pop();
                }
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};