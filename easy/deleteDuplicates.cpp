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
    // keep parent and child pointer. if child == parent, then parent = child->next
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *parent = head;

        while (parent)
        {
            ListNode *child = parent->next;
            if (child && child->val == parent->val)
            {
                parent->next = child->next;
                delete child;
                child = parent->next;
            }
            else
            {
                parent = parent->next;
            }
        }
        return head;
    }
};