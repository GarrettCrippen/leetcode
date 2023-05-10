class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        // node and it's neighbors
        unordered_map<Node *, Node *> mp;
        queue<Node *> q;
        Node *clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            // for each neighbor in neighbors: check if we already 1: created the node, 2: add it as a neighbor
            for (Node *neighbor : curr->neighbors)
            {
                if (mp.find(neighbor) == mp.end())
                {
                    Node *clonedNeighbor = new Node(neighbor->val);
                    mp[neighbor] = clonedNeighbor;
                    mp[curr]->neighbors.push_back(clonedNeighbor);
                    q.push(neighbor);
                }
                else
                {
                    mp[curr]->neighbors.push_back(mp[neighbor]);
                }
            }
        }

        return clone;
    }
};