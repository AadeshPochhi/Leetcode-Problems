class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto &it:blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        vector<vector<bool>>vis(n, vector<bool>(2));
        vector<int>ans(n,-1);
        queue<vector<int>>q;
        q.push({0,0,-1});
        vis[0][1]=true;
        vis[0][0]=true;
        ans[0]=0;
        while(!q.empty()){
            vector<int>curr=q.front(); q.pop();
            int node=curr[0], steps=curr[1], prevColour=curr[2];
            for(auto &[neighbour, colour]:adj[node]){
                if(!vis[neighbour][colour] && prevColour!=colour){
                    vis[neighbour][colour]=true;
                    q.push({neighbour,1+steps,colour});
                    if(ans[neighbour]==-1){
                        ans[neighbour]=1+steps;
                    }
                }
            }
        }
        return ans;
    }
};