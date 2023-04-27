class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd)
    {
        if (preStart >= preorder.size() || inStart > inEnd)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        int pos = 0;

        // use two params instead of searching whole array space
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                pos = i;
                break;
            }
        }

        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, pos - 1);
        root->right = buildTreeHelper(preorder, inorder, preStart + pos - inStart + 1, pos + 1, inEnd);
        return root;
    }
};
