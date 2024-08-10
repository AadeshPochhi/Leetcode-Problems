class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>m;
        int ans=0,ansf=0;
        for(auto edge:edges){
            m[edge[0]]++;
            m[edge[1]]++;
        }
        for(const auto& e:m){
            if(e.second>ansf){
                ansf=e.second;
                ans=e.first;
            }
        }
        if(ansf==edges.size()){
            return ans;
        }
        else return -1;
    }
};