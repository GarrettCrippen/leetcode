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
    // idea have two pointers, so that we can act optimally
    ListNode *swapNodes(ListNode *head, int k)
    {
        // List is N long, and [1..N]
        ListNode *slow = head;
        ListNode *start = head;
        ListNode *end = head;

        int cnt = 0;

        // find length of linked list
        while (slow)
        {
            slow = slow->next;
            cnt++;
        }

        // case where k is in the middle
        if (cnt / 2 == k - 1 && cnt % 2 == 1 && k < cnt)
            return head;

        int pos = cnt - k;
        for (int i = 0; i < pos; i++)
        {
            end = end->next;
        }

        for (int i = 1; i < k; i++)
        {
            start = start->next;
        }

        cout << end->val << endl;
        cout << start->val << endl;

        swap(end->val, start->val);

        return head;
    }
};