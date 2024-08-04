class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarrays;
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        subarrays.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefix[i]=(prefix[i-1]+nums[i])%mod;
            subarrays.push_back(prefix[i]);
        }
        for(int i=1;i<n;i++){
            int j=0;
            while(prefix[i]!=0){
                prefix[i]-=nums[j];
                if(prefix[i]!=0)
                    subarrays.push_back(prefix[i]);
                j++;
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