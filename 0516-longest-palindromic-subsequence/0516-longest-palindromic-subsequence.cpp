class Solution {
public:
    int dp[1001][1001];
    int fun(string &s, int l1,int l2){
        if(l1>l2) return 0;
        if(l1==l2) return 1;
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        int ans=0;
        if(s[l1]!=s[l2]){
            return dp[l1][l2]=max(fun(s,l1+1,l2),fun(s,l1,l2-1));
        }
        else{
            return dp[l1][l2]=2+fun(s,l1+1,l2-1);
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
        return fun(s,0,s.size()-1);
    }
};