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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string s1 = "", s2 = "";
        ListNode *temp = l1;
        while (temp)
        {
            s1.push_back(temp->val + '0');
            temp = temp->next;
        }
        temp = l2;
        while (temp)
        {
            s2.push_back(temp->val + '0');
            temp = temp->next;
        }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        bool carry = false;

        int int_sum = s1[s1.length() - 1] - '0' + s2[s2.length() - 1] - '0';
        if (int_sum >= 10)
        {
            int_sum -= 10;
            carry = true;
        }

        ListNode *head = new ListNode(int_sum);
        ListNode *first = head;

        int p1 = s1.length() - 2, p2 = s2.length() - 2;
        int pp = min(p1, p2);
        while (pp >= 0)
        {
            int int_sum = s1[p1] - '0' + s2[p2] - '0' + (carry ? 1 : 0);
            carry = false;
            if (int_sum >= 10)
            {
                int_sum -= 10;
                carry = true;
            }
            ListNode *tmp = new ListNode(int_sum);
            first->next = tmp;
            first = tmp;
            pp--;
            p1--;
            p2--;
        }
        while (p1 >= 0)
        {
            int_sum = s1[p1] - '0' + (carry ? 1 : 0);
            if (int_sum >= 10)
            {
                int_sum -= 10;
                carry = true;
            }
            else
                carry = false;
            ListNode *tmp = new ListNode(int_sum);
            first->next = tmp;
            first = tmp;
            p1--;
        }

        while (p2 >= 0)
        {
            int_sum = s2[p2] - '0' + (carry ? 1 : 0);
            if (int_sum >= 10)
            {
                int_sum -= 10;
                carry = true;
            }
            else
                carry = false;
            ListNode *tmp = new ListNode(int_sum);
            first->next = tmp;
            first = tmp;
            p2--;
        }

        if (carry)
        {
            ListNode *tmp = new ListNode(1);
            first->next = tmp;
        }

        return head;
    }
};