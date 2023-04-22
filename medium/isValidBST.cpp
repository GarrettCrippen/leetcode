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

// check if valid BST

// input:root
// output:t/f

// idea: use dfs
class Solution
{
private:
    TreeNode *myRoot;

public:
    bool isValidBST(TreeNode *root)
    {
        myRoot = root;
        return recurse(root, INT_MIN, INT_MAX, false, false);
    }
    bool recurse(TreeNode *root, int right, int left, bool l, bool r)
    {
        if (!root)
            return true;

        // check if valid BST
        if (root->val >= left && myRoot != root && l)
        {
            cout << "LEFT IS " << left << endl;
            cout << "INVALID" << root->val << ", LEFT" << endl;
            return false;
        }
        if (root->val <= right && myRoot != root && r)
        {
            cout << "LEFT IS " << left << endl;
            cout << "INVALID" << root->val << ", right" << endl;
            return false;
        }

        // update here if possible
        int right2 = max(right, root->val);
        int left2 = min(left, root->val);

        return recurse(root->left, right, left2, true, r) && recurse(root->right, right2, left, l, true);
    }
};