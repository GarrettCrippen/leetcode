/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// count number of good nodes:
// good = all ancestors are <= curren node
// observe that i is good and i+1 is gt than i, then i+1 is also good.

// can mantain max as param
class Solution
{

public:
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        recurse(root, root->val, count);
        return count;
    }

    void recurse(TreeNode *root, int max_val, int &count)
    {

        if (!root)
            return;

        // compare curr to ancestors
        if (root->val >= max_val)
        {
            count++;
            max_val = root->val;
        }
        recurse(root->right, max_val, count);
        recurse(root->left, max_val, count);
    }
};