class Solution {
public:
    int dp[301];
    bool fun(int i, string &s,vector<string>& wordDict){
        if(i>=s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.length();j++){
            string temp=s.substr(i,j-i+1);
            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
                if(fun(j+1,s,wordDict)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        return fun(0,s,wordDict);
    }
};