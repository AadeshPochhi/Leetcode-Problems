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
typedef long long ll;
class Solution {
public:
    void inorder(TreeNode* root,vector<ll>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    
    int findminn(vector<ll>&in,ll num){
        ll i=0,j=in.size()-1;
        ll ans=-1;
        while(i<=j){
            ll m=i+((j-i)>>1);
            if(in[m]>num){
                j=m-1;
            }
            else if(in[m]==num){
                return in[m];
            }
            else{
                ans=in[m];
                i=m+1;
            }
        }
        return ans; 
    } 
    
    int findmaxx(vector<ll>&in,ll num){
        ll i=0, j=in.size()-1;
        int ans=-1;
        while(i<=j){
            ll m=i+((j-i)>>1);
            if(in[m]<num){
                i=m+1;
            }
            else if(in[m]==num){
                return in[m];
            }
            else{
                ans=in[m];
                j=m-1;
            }
        }
        return ans;
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<ll>in;
        inorder(root,in);
        vector<vector<int>> ans;
        for(ll i=0;i<queries.size();i++){
            int minn=findminn(in,queries[i]);
            int maxx=findmaxx(in,queries[i]);
            ans.push_back({minn,maxx});            
        }
        
        return ans;
    }
};