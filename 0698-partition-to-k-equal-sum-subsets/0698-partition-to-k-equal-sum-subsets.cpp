class Solution {
public:
    bool fun(vector<int>& nums, vector<bool>&vis,int target,int sum,int i,int k){
        if(k==1) return true;
        if(i>=nums.size()) return false;
        if(sum==target){
            return fun(nums,vis,target,0,0,k-1);
        }
        for(int j=i;j<nums.size();j++){
            if(vis[j] || nums[j]+sum>target) continue;
            
            vis[j]=true;
            if(fun(nums,vis,target,sum+nums[j],j+1,k)) return true;
            vis[j]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(nums.size()<k) return false;
        if(sum%k) return false;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<bool> vis(nums.size(),false);
        return fun(nums,vis,sum/k,0,0,k);
    }
};