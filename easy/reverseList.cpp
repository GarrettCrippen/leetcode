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
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *temp = head;
        stack<ListNode *> my_stack;

        // push all nodes onto stack...
        while (temp)
        {
            my_stack.push(temp);
            temp = temp->next;
        }
        // retreive nodes and append to list
        ListNode *myHead = my_stack.top();
        my_stack.pop();
        temp = myHead;
        while (!my_stack.empty())
        {
            ListNode *temp2 = my_stack.top();
            my_stack.pop();
            temp->next = temp2;
            temp = temp2;
        }
        temp->next = nullptr;

        return myHead;
    }
};