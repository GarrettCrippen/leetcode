/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // just store all nodes in a map
    bool hasCycle(ListNode *head)
    {
        // map<ListNode*,int>my_map;
        // ListNode* temp = head;

        // while(temp){
        //     if(my_map.count(temp)>0){
        //         return true;
        //     }
        //     my_map[temp]=1;
        //     temp=temp->next;
        // }

        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};