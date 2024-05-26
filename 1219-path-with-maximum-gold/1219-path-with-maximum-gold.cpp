class Solution {
public:
    vector<vector<int>> vis;
    int maxGold(vector<vector<int>> &mat,int x,int y){
        int n=mat.size(),m=mat[0].size();
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || !mat[x][y])           return 0;
        vis[x][y]=1;
        int ans=mat[x][y]+max({maxGold(mat,x+1,y),maxGold(mat,x-1,y),maxGold(mat,x,y-1),maxGold(mat,x,y+1)});
        vis[x][y]=0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vis=vector<vector<int>> (n,vector<int> (m));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=max(ans,maxGold(mat,i,j));
        return ans;
    }
};