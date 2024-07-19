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
    pair<int, TreeNode*> postorder(TreeNode* root){
        if(root==NULL){
            return {0,NULL};
        }
        pair<int, TreeNode*> l=postorder(root->left);
        pair<int, TreeNode*> r=postorder(root->right);
        
        if(l.first==r.first){
            return {l.first+1,root};
        }
        else if(l.first>r.first){
            return {l.first+1,l.second};
        }
        else{
            return {r.first+1,r.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*>result=postorder(root);
        return result.second;
    }
};