class Solution {
public:
    int dp[10001];
    int solve(vector<int>& coins,int a){
        if(a==0) return 0;
        if(a<0) return INT_MAX;
        if(dp[a]!=-1) return dp[a];
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins,a-coins[i]);
            if(ans != INT_MAX)
                mini = min(mini,1 + ans);
        }
        return dp[a]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans=solve(coins,amount);
        if(ans != INT_MAX) return ans;
        return -1;
    }
};