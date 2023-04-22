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
    int max_height = 0;

public:
    // [0,2000] nodes
    // input: root
    // output: level order

    // idea serialize by height pushback() onto vector<int>
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        // here's bfs implementation
        if (!root)
            return vector<vector<int>>();

        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            vector<int> temp;

            for (int i = 0; i < count; i++)
            {
                TreeNode *cur = q.front();
                q.pop();

                // if(!cur){
                //     continue;
                // }
                temp.push_back(cur->val);

                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            res.push_back(temp);
        }
        return res;

        // if(!root)
        //     return vector<vector<int>>();

        // vector<vector<int>>v(2000);
        // recurse(root,0,v);
        // v.resize(max_height+1);
        // return v;
    }

    // //run dfs to store val at each level
    // void recurse(TreeNode* root, int height,vector<vector<int>>&v){
    //     if(!root)return;

    //     max_height = max(max_height,height);

    //     v[height].push_back(root->val);

    //     recurse(root->left,height+1,v);
    //     recurse(root->right,height+1,v);
    // }
};