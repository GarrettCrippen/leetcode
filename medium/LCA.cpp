/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Goal: find Lowest ancestor of two nodes
// note node can be an ancestory of himself

// idea: save ancestors => too much memory
// dfs untill you reach p or q, save path

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        set<TreeNode *> s1, s2, intersect;
        recurse(root, p, s1, s1);
        recurse(root, q, s2, s2);

        set_intersection(s1.begin(), s1.end(),
                         s2.begin(), s2.end(),
                         inserter(intersect, intersect.begin()));

        return *intersect.rbegin();
    }

    // hopefully set is minimal
    void recurse(TreeNode *root, TreeNode *target, set<TreeNode *> t, set<TreeNode *> &s)
    {
        if (!root)
            return;

        // temp
        t.insert(root);
        if (root == target)
        {
            s = t;
        }

        recurse(root->left, target, t, s);
        recurse(root->right, target, t, s);
    }
};