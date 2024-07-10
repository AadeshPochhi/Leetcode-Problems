class Solution {
public:
    bool util(int v, vector<vector<int>>& graph, vector<int> &colour){
        colour[v]=1;
        queue<int>q;
        q.push(v);
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(int i:graph[node]){
                if(colour[i]==-1){
                    colour[i]=1-colour[node];
                    q.push(i);
                }
                else if(colour[i]==colour[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>colour(V,-1);
        for(int i=0;i<V;i++){
            if(colour[i]==-1 && !util(i,graph,colour))
                return false;
        }
        return true;
    }
};