class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> ans1(n);
        ans1[0]=nums[0];
        int res=ans1[0];
        for(int i=1;i<n;i++){
            ans1[i]=max(nums[i]+ans1[i-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            res=max(res,ans1[i]);
        }
        vector<int> ans2(n);
        ans2[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans2[i]=max(nums[i],nums[i]+ans2[i+1]);
        }
        for(int i=1;i<n-1;i++){
            res=max(res,ans1[i-1]+ans2[i+1]);
        }
        return res;
    }
};