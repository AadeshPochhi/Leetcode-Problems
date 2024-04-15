class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    ans=max(ans,dp[j]);
                }
            }
            ans+=1;
            dp[i]=ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
};