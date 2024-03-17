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
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);que.push(NULL);
        while(que.front()!=NULL)
        {
            vector<int> v;
            while(que.front()!=NULL)
            {
                auto node=que.front();que.pop();
                v.push_back(node->val);
                if(node->left!=NULL) que.push(node->left);
                if(node->right!=NULL) que.push(node->right);
            }
            que.push(NULL);
            que.pop();
            ans.push_back(v);
        }
        return ans[ans.size()-1][0];
    }
};