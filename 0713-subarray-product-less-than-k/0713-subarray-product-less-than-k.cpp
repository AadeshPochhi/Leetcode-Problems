class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=-1,p=1,ans=0;
        int n=nums.size();
        while(l<n){
            if(r<l){
                r=l-1;
            }
            while(r+1<n && p*nums[r+1]<k){
                p*=nums[r+1];
                r++;
            }
            ans+=r-l+1;
            if(p%nums[l]==0){p/=nums[l];}
            l++;
        }
        return ans;
    }
};