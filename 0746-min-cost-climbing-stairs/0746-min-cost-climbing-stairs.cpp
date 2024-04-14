class Solution {
public:
    int ans[1001];
    int fun(int i, vector<int>& cost){
        if(i>=cost.size()) return 0;
        if(ans[i]!=-1){
            return ans[i];
        }
        int c1=cost[i]+fun(i+1,cost);
        int c2=cost[i]+fun(i+2,cost);
        
        return ans[i]=min(c1,c2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(ans,-1,sizeof ans);
        int res=fun(0,cost);
        if(cost.size()>1){
            res=min(res,fun(1,cost));
        }
        return res;
    }
};