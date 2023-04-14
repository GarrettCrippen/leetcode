/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// iterate through head->next and then allocate
//  save each node in a datastructure (index)
//  then iterate again and point random to the nodes in the data structure
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;

        if (!head)
        {
            return head;
        }

        Node *first = new Node(head->val);
        Node *myHead = first;

        map<Node *, Node *> my_map;
        my_map[head] = first;
        while (temp)
        {
            temp = temp->next;
            if (temp)
            {
                Node *myNode = new Node(temp->val);
                my_map[temp] = myNode;
                first->next = myNode;
                first = myNode;
            }
        }

        temp = head;

        first = myHead;
        while (temp)
        {

            first->random = my_map[temp->random];

            first = first->next;
            temp = temp->next;
        }
        return myHead;
    }
};