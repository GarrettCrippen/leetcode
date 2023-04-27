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
private:
    int mink = INT_MAX;

public:
    // k <= n

    // find the largest number, then subtract k
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return mink + k - 1;
        mink = min(root->val, mink);
        return kthSmallest(root->left, k);
    }
};