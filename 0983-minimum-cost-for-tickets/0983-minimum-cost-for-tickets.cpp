class Solution {
public:
    int solve_using_recursion(vector<int>& days, vector<int>& costs,int i){
        if(i>=days.size()) return 0;
        int c1=costs[0]+solve_using_recursion(days,costs,i+1);
        int lastDay=days[i]+6;
        int j=i;
        while(j<days.size() && days[j]<=lastDay) j++;
        int c7=costs[1]+solve_using_recursion(days,costs,j);
        lastDay=days[i]+29;
        j=i;
        while(j<days.size() && days[j]<=lastDay) j++;
        int c30=costs[2]+solve_using_recursion(days,costs,j);
        return min(c1,min(c7,c30));

    }
    int solve_using_mem(vector<int>& days, vector<int>& costs,int i,vector<int>& dp){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int c1=costs[0]+solve_using_mem(days,costs,i+1,dp);
        int lastDay=days[i]+6;
        int j=i;
        while(j<days.size() && days[j]<=lastDay) j++;
        int c7=costs[1]+solve_using_mem(days,costs,j,dp);
        lastDay=days[i]+29;
        j=i;
        while(j<days.size() && days[j]<=lastDay) j++;
        int c30=costs[2]+solve_using_mem(days,costs,j,dp);
        return dp[i]=min(c1,min(c7,c30));
    }
    int solve_using_tabulation(vector<int>& days, vector<int>& costs){
        vector<int> dp(days.size()+1,0);
        for(int i=days.size()-1;i>=0;i--){
            int c1=costs[0]+dp[i+1];
            int lastDay=days[i]+6;
            int j=i;
            while(j<days.size() && days[j]<=lastDay) j++;
            int c7=costs[1]+dp[j];
            lastDay=days[i]+29;
            j=i;
            while(j<days.size() && days[j]<=lastDay) j++;
            int c30=costs[2]+dp[j];
            dp[i]=min(c1,min(c7,c30));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //return solve_using_recursion(days,costs,0);
        
        vector<int> dp(days.size()+1,-1);
        return solve_using_mem(days,costs,0,dp);
        
        //return solve_using_tabulation(days,costs);
    }
};