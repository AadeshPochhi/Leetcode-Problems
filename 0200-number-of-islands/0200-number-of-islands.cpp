class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>>q;
        int ans=0;
        vector<pair<int,int>> dr={{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    q.push({i,j});
                
                    while(!q.empty()){
                        auto [x,y]=q.front(); q.pop();
                        
                        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='0')
                            continue;
                        
                         grid[x][y]='0';
                        
                        for(auto dir:dr){
                            int nx=x+dir.first;
                            int ny=y+dir.second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
                                q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};