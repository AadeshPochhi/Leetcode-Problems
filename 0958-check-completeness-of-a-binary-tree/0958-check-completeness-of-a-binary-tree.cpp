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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        bool flag=true;
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            if(n==NULL) count++;
            else{
                if(!count){
                    q.push(n->left);
                    q.push(n->right);
                }
                if(count){
                    flag=false;
                }
            }
        }
        return flag;
    }
};