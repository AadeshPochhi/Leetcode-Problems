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
    int sum=0;
    void sumofleft(TreeNode* root){
        if(root==NULL) return;
        sumofleft(root->left);
        if(root->left && !root->left->left && !root->left->right)sum+=root->left->val;
        sumofleft(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sumofleft(root);
        return sum;
    }
};