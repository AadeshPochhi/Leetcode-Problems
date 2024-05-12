class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof dp);
        string ans="";
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        ans=s[0];
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {dp[i][i+1]=1; ans=s.substr(i,2);}
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1) {
                    dp[i][j]=1;
                    ans=s.substr(i,l);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
};