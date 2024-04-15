class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Method 1:
        // int ans=-1e9;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     if(sum<0){
        //         sum=0;
        //     }
        //     sum+=nums[i];
        //     ans=max(ans,sum);
        // }
        // return ans;
        
        //Method 2:
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>(nums[i]+ans[i-1])) ans[i]=nums[i];
            else{
                ans[i]=nums[i]+ans[i-1];
            }
        }
        return *max_element(ans.begin(),ans.end());
        
    }
};