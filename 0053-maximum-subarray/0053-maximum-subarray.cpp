class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Method 1:
        int ans=-1e9;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum+=nums[i];
            ans=max(ans,sum);
        }
        return ans;
        
        // //Method 2:  TC:O(n)  SC:O(n)
        // int n=nums.size();
        // if(n==1) return nums[0];
        // vector<int> ans(n);
        // ans[0]=nums[0];
        // int res=ans[0];
        // for(int i=1;i<n;i++){
        //     ans[i]=max(nums[i]+ans[i-1],nums[i]);
        //     res=max(res,ans[i]);
        // }
        // return res;
        
        
        // Method 3: TC:O(n)  SC:O(1)
        // int n=nums.size();
        // if(n==1) return nums[0];
        // int prev=nums[0];
        // int res=prev;
        // for(int i=1;i<n;i++){
        //     prev=max(nums[i]+prev,nums[i]);
        //     res=max(res,prev);
        // }
        // return res;
        
    }
};