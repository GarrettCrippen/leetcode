/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // alternate i, n, i-1,n-1, i-2,n-2
public:
    void reorderList(ListNode *head)
    {
        queue<ListNode *> q;
        stack<ListNode *> st;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            q.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow)
        {
            st.push(slow);

            slow = slow->next;
        }

        bool even = true;
        while (!q.empty() && !st.empty())
        {
            if (even)
            {
                q.front()->next = st.top();
                q.pop();
                even = false;
            }
            else
            {
                st.top()->next = q.front();
                st.pop();
                even = true;
            }
        }

        ListNode *temp;
        if (!q.empty())
        {
            cout << "q" << endl;
            temp = q.front();
            q.pop();
            if (!q.empty())
            {
                temp->next = q.front();
                q.front()->next = nullptr;
            }
            else
                temp->next = nullptr;
        }

        if (!st.empty())
        {
            cout << "st" << endl;
            temp = st.top();
            st.pop();
            if (!st.empty())
            {
                temp->next = st.top();
                st.top()->next = nullptr;
            }
            else
                temp->next = nullptr;
        }
    }
};