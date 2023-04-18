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
    // use logical operator and recurse
    // height can be found by taking the max of left and right subchildren +1
    bool isBalanced(TreeNode *root)
    {
        bool b = true;
        recurse(root, b);
        return b;
    }
    int recurse(TreeNode *root, bool &b)
    {
        if (!root)
            return 0;

        int left = recurse(root->left, b) + 1;
        int right = recurse(root->right, b) + 1;
        // heights differ by more than 1
        b &= abs(left - right) <= 1;
        // cout<<"diff"<<abs(left-right)<<endl;

        return max(left, right);
    }
};