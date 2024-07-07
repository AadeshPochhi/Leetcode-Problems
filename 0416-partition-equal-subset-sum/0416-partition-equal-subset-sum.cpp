class Solution {
public:
    bool f(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return (nums[0]==target);
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake=f(i-1,target,nums,dp);
        bool take=false;
        if(nums[i]<target) take=f(i-1,target-nums[i],nums,dp);
        return dp[i][target]=take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return f(nums.size()-1,target,nums,dp);
    }
};