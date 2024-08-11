class Solution {
public:
    void dfs(int r, int c, set<pair<int,int>>&vis, vector<vector<int>>& grid){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || vis.find({r,c})!=vis.end() || grid[r][c]!=1){
            return;
        }
        vis.insert({r,c});
        vector<pair<int,int>>dir={{r+1,c},{r,c+1},{r,c-1},{r-1,c}};
        for(int i=0;i<4;i++){
            dfs(dir[i].first,dir[i].second,vis,grid);
        }
    }
    int countDays(set<pair<int,int>>&vis, vector<vector<int>>& grid){
        int R=grid.size();
        int C=grid[0].size();
        int count=0;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(grid[r][c] && vis.find({r,c})==vis.end()){
                    dfs(r,c,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        set<pair<int,int>>vis;
        if(countDays(vis,grid)!=1) return 0;
        for(auto &it:vis){
            grid[it.first][it.second]=0;
            set<pair<int,int>>vis;
            if(countDays(vis,grid)!=1) return 1;
            grid[it.first][it.second]=1;
        }
        return 2;
    }
};