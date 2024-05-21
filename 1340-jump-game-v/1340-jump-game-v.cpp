class Solution {
public:
    int fun(int i, int n, vector<int>& arr, int d,vector<int>& dp){
        if(i>=n) return 0;
        if(i<0) return 0;
        if(i<n-1 && i>0 && arr[i+1]>arr[i] && arr[i-1]>arr[i]) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int maxi=0;
        for(int j=1;j<=d;j++){
            if((i+j<n) && arr[i+j]>=arr[i]) break;
            maxi=max(maxi,1+fun(i+j,n,arr,d,dp));
        }
        for(int j=1;j<=d;j++){
            if((i-j>=0) &&arr[i-j]>=arr[i]) break;
            maxi=max(maxi,1+fun(i-j,n,arr,d,dp));
        }
        return dp[i]=maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,fun(i,n,arr,d,dp));
        }
        return ans;
    }
};