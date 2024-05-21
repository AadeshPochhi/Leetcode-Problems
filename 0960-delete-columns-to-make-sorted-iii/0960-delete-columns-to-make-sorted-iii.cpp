class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int l=strs[0].size();
        vector<int>dp(l,1);
        int res=1;
        for(int i=1;i<l;i++){
            for(int j=0;j<i;j++){
                bool update=true;
                for(auto s:strs){
                    if(s[i]<s[j]){
                        update=false;
                        break;
                    }
                }
                if(!update) continue;
                dp[i]=max(dp[j]+1,dp[i]);
                res=max(dp[i],res);
            }
        }
        return l-res;
    }
};