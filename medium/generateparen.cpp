class Solution
{
public:
    // n = 1  -> ()
    //  n =2 -> (()), ()()
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        stack<char> st;
        generate(0, 0, n, res, st);
        return res;
    }

    void generate(int open, int closed, int n, vector<string> &result, stack<char> st)
    {
        if (open < n)
        {
            st.push(')');
            generate(open + 1, closed, n, result, st);
            st.pop();
        }
        if (closed < open)
        {
            st.push('(');
            generate(open, closed + 1, n, result, st);
            st.pop();
        }
        if (closed == open && open == n)
        {
            string temp = "";
            while (!st.empty())
            {
                temp += st.top();
                st.pop();
            }
            result.push_back(temp);
        }
    }
};