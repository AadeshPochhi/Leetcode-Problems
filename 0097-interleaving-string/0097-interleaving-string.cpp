class Solution {
public:
    int dp[101][101][201];
    int n , m, N;
    
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3 )
    {
        if(i==n && j==m && k==N)
            return true;
        
        if(k>=N)
            return false;
        
        if(dp[i][j][k] !=-1)
        {
            return dp[i][j][k];
        }
        bool res = false;
        if(s1[i] == s3[k])
        {
            res = solve(i+1,j,k+1,s1,s2,s3);
        }
        
        if(res)
            return res;
        
        if(s2[j] == s3[k])
        {
            res = solve(i,j+1,k+1,s1,s2,s3);
        }
        
        return dp[i][j][k] = res;
        
        
            
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,0,s1,s2,s3);
    }
};