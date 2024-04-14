class Solution {
public:
    int ans[45];
    int fun(int i,int n){
        if(i>=n) return 1;
        if(ans[i]!=-1) return ans[i];
        int res=fun(i+1,n);
        if(i+2<=n){
            res+=fun(i+2,n);
        }
        return ans[i]=res;
    }
    int climbStairs(int n) {
        memset(ans,-1,sizeof ans);
        return fun(0,n);
    }
};