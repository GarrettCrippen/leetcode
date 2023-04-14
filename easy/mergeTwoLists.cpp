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
    // need temporary pointer to point to children
    // base-case: no nodes
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // covers base case where lists are empty
        if (list1 == nullptr)
        {
            if (list2 == nullptr)
            {
                return nullptr;
            }
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // Iterate through with two pointers and a temp var
        ListNode *head1 = list1;
        ListNode *head2 = list2;

        // 4 ptrs: head and tail for my list + 1 pointer for each linked list
        ListNode *myHead;
        if (head1->val <= head2->val)
        {
            myHead = head1;
            head1 = head1->next;
        }
        else
        {
            myHead = head2;
            head2 = head2->next;
        }
        ListNode *myTail = myHead;

        while (head1 and head2)
        {
            if (head1->val <= head2->val)
            {
                myTail->next = head1;
                myTail = head1;
                head1 = head1->next;
            }
            else
            {
                myTail->next = head2;
                myTail = head2;
                head2 = head2->next;
            }
        }

        if (head1)
        {
            myTail->next = head1;
        }
        else if (head2)
        {
            myTail->next = head2;
        }

        return myHead;
    }
};