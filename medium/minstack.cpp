class MinStack
{
public:
    int min, temp;
    // keep track of 2min if, if we pop we can set it as min
    stack<int> st;
    MinStack()
    {
        min = INT_MAX;
        temp = INT_MAX;
    }
    // p2 p0 p3 p0
    // push and set new min if it is
    void push(int val)
    {
        // if new min then, temp is lost and is now min, and min is val
        if (val <= min)
        {
            temp = min;
            min = val;
            cout << "PU NEW MIN = " << val << endl;
        }
        st.push(val);
    }

    // set min to 2nd min
    void pop()
    {
        if (st.top() == min)
        {
            cout << "PNEW MIN = " << temp << endl;
            min = temp;
            temp = INT_MAX;
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        if (min == INT_MAX)
            return st.top();
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */