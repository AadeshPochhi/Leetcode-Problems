class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        int R=grid.size(); int C=grid[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==1) fresh+=1;
                else if(grid[i][j]==2) q.emplace(i,j);
            }
        }
        vector<pair<int,int>> dr={{1,0},{-1,0},{0,1},{0,-1}};
        int time=-1;
        q.emplace(-1,-1);
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            if(r==-1){
                time++;
                if(!q.empty()){
                    q.emplace(-1,-1);
                }
            }
            else{
                for(auto [dirr,dirc]:dr){
                    int nr=r+dirr;
                    int nc=c+dirc;
                    if(nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.emplace(nr,nc);
                    }
                }
            }
        }
        return fresh==0?time:-1;
    }
};