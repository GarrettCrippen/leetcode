class Solution
{
public:
    // push numbers, pop twice for operators and then push result
    //[-200,200]
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (auto it = tokens.begin(); it != tokens.end(); it++)
        {

            int expr;
            // iterate over digits instead
            try
            {
                int digit = stoi(*it);
                st.push(digit);
                cout << "PUSH: " << st.top() << endl;
            }
            catch (exception &e)
            {
                char s = (*it)[0];

                int operand1 = st.top();
                st.pop();
                cout << "POP: " << operand1 << endl;
                int operand2 = st.top();
                st.pop();
                cout << "POP: " << operand2 << endl;
                switch (s)
                {
                case '*':
                    expr = operand2 * operand1;
                    break;
                case '/':
                    expr = operand2 / operand1;
                    break;
                case '+':
                    expr = operand2 + operand1;
                    break;
                case '-':
                    expr = operand2 - operand1;
                    break;
                }
                cout << "PUSHING EXPR:" << expr << endl;
                // push expression
                st.push(expr);
            }
        }
        return st.top();
    }
};