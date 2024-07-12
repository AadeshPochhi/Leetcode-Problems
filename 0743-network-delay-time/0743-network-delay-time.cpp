class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto vec:times)
            adj[vec[0]].push_back({vec[1],vec[2]});
        
        vector<int>result(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        result[k]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int dist=vec.second;
                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};