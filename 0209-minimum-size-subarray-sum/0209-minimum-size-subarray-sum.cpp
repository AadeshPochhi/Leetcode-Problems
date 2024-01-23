class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
       vector<int> prefix(n,0);
       prefix[0]=nums[0];
       for(int i=1;i<nums.size();i++){
           prefix[i]=nums[i]+prefix[i-1];
       }
       if(prefix[n-1]<target){
           return 0;
       }
       int ans=n;
       for(int i=0;i<nums.size();i++){
           auto zt=lower_bound(prefix.begin()+i,prefix.end(),target-nums[i]+prefix[i]);
           auto it=prefix.begin()+i;
           int num=zt-it+1;

           if(zt!=prefix.end()) ans=min(ans,num);
       }
       return ans;
    }
};