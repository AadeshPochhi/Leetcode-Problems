class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int, vector<int>, greater<int>> subarrays;
        int prefix;
        for(int i=0;i<n;i++){
            prefix=0;
            for(int j=i;j<n;j++){
                prefix+=nums[j];
                prefix%=mod;
                subarrays.push(prefix);
            }
        }
        int res=0;
        for(int i=1;i<=right;i++){
            int val=subarrays.top();
            subarrays.pop();
            if(i>=left){
                res+=val;
                res%=mod;
            }
        }
        return res;
    }
};