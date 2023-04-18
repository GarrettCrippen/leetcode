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
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int my_max = 0;
        recurse(root, my_max);
        return my_max;
    }

    int recurse(TreeNode *root, int &my_max)
    {
        if (!root)
            return -1;

        int left = recurse(root->left, my_max);
        int right = recurse(root->right, my_max);

        if (left + right + 2 > my_max)
            my_max = left + right + 2;

        return 1 + max(left, right);
    }
};