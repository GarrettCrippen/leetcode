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

// run bfs and return largest sum

class Solution
{
private:
    vector<int> depth;
    int maxSum;
    int maxDepth = 0;

public:
    int maxLevelSum(TreeNode *root)
    {

        recurse(root, 1);

        // max_element(this->depth.begin(),this->depth.end())
        //  for(int s: this->depth){
        //      cout<<s<<endl;
        //  }
        this->depth.resize(maxDepth);
        return distance(this->depth.begin(), max_element(this->depth.begin(), this->depth.end())) + 1;
    }

    void recurse(TreeNode *root, int depth)
    {

        this->depth.resize(10e4, 0);
        if (!root)
            return;

        this->depth[depth - 1] += root->val;
        recurse(root->left, depth + 1);
        recurse(root->right, depth + 1);

        this->maxDepth = max(this->maxDepth, depth);
    }
};