class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1]=1;
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};