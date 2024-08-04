class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarrays;
        int prefix;
        for(int i=0;i<n;i++){
            prefix=0;
            for(int j=i;j<n;j++){
                prefix+=nums[j];
                prefix%=mod;
                subarrays.push_back(prefix);
            }
        }
        sort(subarrays.begin(),subarrays.end());
        int res=0;
        for(int i=left-1;i<=(right-1);i++){
            res+=subarrays[i];
            res%=mod;
        }
        return res;
    }
};