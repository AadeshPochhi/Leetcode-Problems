class Solution {
public:
    
    bool search(vector<vector<char>>& board, string word,int r,int c,int k,int m,int n){
        if(k==word.length())    return true;
        if(r<0 ||r==m||c<0||c==n||board[r][c]!=word[k]||board[r][c]=='1')   return false;
        
        char ch=board[r][c];
        board[r][c]='1';
        bool up=search(board,word,r-1,c,k+1,m,n);
        bool down=search(board,word,r+1,c,k+1,m,n);
        bool right=search(board,word,r,c+1,k+1,m,n);
        bool left=search(board,word,r,c-1,k+1,m,n);
        
        board[r][c]=ch;
        
        return up||down||right||left;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[k]){
                    if(search(board,word,i,j,k,m,n))
                        return true;
                }
            }
        }
        return false;
    }
};