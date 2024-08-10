class Solution {
public:
    void dfs(int r, int c, set<pair<int,int>>&vis, int n, vector<vector<int>>&grid2){
        if(r<0 || c<0 || r==n || c==n || vis.find({r,c})!=vis.end() || grid2[r][c]!=0)
            return;
        vis.insert({r,c});
        vector<pair<int,int>>dir={{r+1,c},{r-1,c},{r,c+1},{r,c-1}};
        for(auto d:dir){
            dfs(d.first,d.second,vis,n,grid2);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int N=grid.size();
        int n=3*N;
        vector<vector<int>>grid2(n, vector<int>(n,0));
        set<pair<int,int>>vis;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int R = 3 * r, C = 3 * c;
                if (grid[r][c] == '/') {
                    grid2[R][C + 2] = 1;
                    grid2[R + 1][C + 1] = 1;
                    grid2[R + 2][C] = 1;
                } else if (grid[r][c] == '\\') {
                    grid2[R][C] = 1;
                    grid2[R + 1][C + 1] = 1;
                    grid2[R + 2][C + 2] = 1;
                }
            }
        }
        int res=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid2[r][c]==0 && vis.find({r,c})==vis.end()){
                    dfs(r,c,vis,n,grid2);
                    res+=1;
                }
            }
        }   
        return res;
    }
};