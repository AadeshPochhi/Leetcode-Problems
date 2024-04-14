class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least=INT_MAX;
        int maxprof=0,prof=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<least){
                least=prices[i];
            }
            prof=prices[i]-least;
            maxprof=max(maxprof,prof);
        }
        return maxprof;
    }
};