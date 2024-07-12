class Solution {
public:
//     void dfs(vector<vector<int>>& rooms, int src, vector<bool> &vis){
//         vis[src]=true;
        
//         for(int &node:rooms[src]){
//             if(!vis[node])  
//                 dfs(rooms,node,vis);
//         } 
//     }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        
//         dfs(rooms,0,vis);
        
//         for(bool x:vis){
//             if(!x)
//                 return false;
//         }
//         return true;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front(); q.pop();
            vis[node]=true;
            for(int i=0;i<rooms[node].size();i++){
                if(!vis[rooms[node][i]])
                    q.push(rooms[node][i]);
            }
        }
                
        for(bool x:vis){
            if(!x)
                return false;
        }
        return true;
    }
};