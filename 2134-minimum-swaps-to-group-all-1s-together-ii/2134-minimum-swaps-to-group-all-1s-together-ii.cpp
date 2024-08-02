class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=accumulate(nums.begin(),nums.end(),0);
        int cnt=accumulate(nums.begin(),nums.begin()+k,0);
        int mx=cnt;
        for(int i=k;i<n+k;i++){
            cnt+=nums[i % n]-nums[(i - k + n) % n];
            mx=max(mx,cnt);
        }
        return k-mx;
    }
};