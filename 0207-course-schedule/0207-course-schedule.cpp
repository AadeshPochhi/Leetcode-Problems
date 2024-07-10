class Solution {
public:
    bool dfs(int v, vector<int> adj[], vector<int> &vis, vector<int> &stack){
        if(stack[v]==1) return false;
        if(vis[v]==1) return true;
        vis[v]=1;
        stack[v]=1;
        for(int it:adj[v]){
            if(!dfs(it,adj,vis,stack)){
                return false;
            }
        }
        stack[v]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<int>vis(numCourses,0);
        vector<int>stack(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,adj,vis,stack)){
                return false;
            }
        }
        return true;
    }
};