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
    set<int> heights;

public:
    // return right side nodes or left if doesnt exist
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return vector<int>();

        vector<int> temp;
        recurse(root, temp, 0);

        return temp;
    }

    // observe that odd nodes are the right most
    void recurse(TreeNode *root, vector<int> &temp, int height)
    {
        if (!root)
            return;

        if (heights.find(height) == heights.end())
        {
            temp.push_back(root->val);
            heights.insert(height);
        }

        recurse(root->right, temp, height + 1);
        recurse(root->left, temp, height + 1);
    }
};