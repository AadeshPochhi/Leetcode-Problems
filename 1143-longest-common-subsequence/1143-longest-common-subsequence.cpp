class Solution {
public:
    int dp[1001][1001];
    int fun(int i, int j, string &s, string &t){
        if(i==s.length() || j==t.length()) return 0;
        int ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=t[j]){
            ans=max({fun(i+1,j,s,t),fun(i,j+1,s,t),fun(i+1,j+1,s,t)});
        }
        else{
            ans=1+fun(i+1,j+1,s,t);
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return fun(0,0,text1,text2);
    }
};