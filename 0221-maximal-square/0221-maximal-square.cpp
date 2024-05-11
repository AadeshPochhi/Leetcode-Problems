class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        if(m==0||n==0) return 0;
        int dp[m+1][n+1];
        memset(dp,0,sizeof dp);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='1'){
                    dp[i+1][j+1]=min(dp[i][j],min(dp[i][j+1],dp[i+1][j]))+1;
                    ans=max(ans,dp[i+1][j+1]);  
                }
            }
        }
        return ans*ans;
    }
};