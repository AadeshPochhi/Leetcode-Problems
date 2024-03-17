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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,unsigned long long>> q;
        q.push({root,1});
        unsigned long long ans = 0;
        while(!q.empty()) {
            unsigned long long start = q.front().second;
            int sz = q.size();
            unsigned long long end;
            for(int i=0;i<sz;i++) {
                auto n = q.front();
                q.pop();
                end = n.second;
                if(n.first->left) q.push({n.first->left,2*n.second});
                if(n.first->right) q.push({n.first->right,2*n.second + 1});
            }
            ans = max(ans,end-start+1);
        }
        return static_cast<int>(ans);
    }
};