class Solution {
public: 
    int dp[301][5001];
    int solve(int amount,vector<int>coins,int i,int a){
        if(a==amount) return 1;
        if(a>amount) return 0;
        if(i==coins.size()) return 0;
        if(dp[i][a]!=-1) return dp[i][a];
        return dp[i][a]=solve(amount,coins,i,a+coins[i])+solve(amount,coins,i+1,a);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return solve(amount,coins,0,0);
    }
};