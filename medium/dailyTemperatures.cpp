class Solution
{
public:
    // input: array of temperatures
    // output: a_i = #days to get a warmer temperature or 0

    // use a stack and find next greater element
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;

        // push first idnex
        st.push(0);
        // push each index onto the stack
        for (int i = 1; i < temperatures.size(); i++)
        {
            // if top of stack is less than current index, then set the top of the stack to the distance of the two
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};