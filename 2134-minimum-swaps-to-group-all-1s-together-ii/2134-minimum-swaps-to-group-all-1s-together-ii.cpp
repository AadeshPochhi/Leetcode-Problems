class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(), k=0;
        for(int i=0;i<n;i++){
            k+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<k;i++){
            cnt+=nums[i];
        }
        int mx=cnt;
        for(int i=k;i<n+k;i++){
            cnt+=nums[i % n]-nums[(i - k + n) % n];
            mx=max(mx,cnt);
        }
        return k-mx;
    }
};