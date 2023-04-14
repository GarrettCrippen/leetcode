/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  let's mantain a map of visited node ptrs
// return -1 if no cycle, otherwise return duplicate node ptr
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        map<ListNode *, int> myMap;
        ListNode *temp = head;

        while (temp)
        {
            if (myMap.count(temp) > 0)
            {
                return temp;
            }
            myMap[temp] = 1;
            temp = temp->next;
        }
        return temp;
    }
};

// Let's implement two pointer approach
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast and fast->next and slow)
        {

            slow = slow->next;
            fast = fast->next->next;

            // found a cycle
            if (fast == slow)
            {
                // start fast at the begininning again
                fast = head;
                while (fast and slow)
                {

                    if (fast == slow)
                    {
                        return fast;
                    }

                    // fast is a slow pointer here
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        return nullptr;
    }
};