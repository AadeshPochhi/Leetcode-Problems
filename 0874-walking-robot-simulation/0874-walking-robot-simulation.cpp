class Solution {
public:
    string solve(string dir, int val){
        if(val==-1){
            if(dir=="+x") dir="-y";
            else if(dir=="-x") dir="+y";
            else if(dir=="+y") dir="+x";
            else if(dir=="-y") dir="-x";
        }
        else if(val==-2){
            if(dir=="+x") dir="+y";
            else if(dir=="-x") dir="-y";
            else if(dir=="+y") dir="-x";
            else if(dir=="-y") dir="+x";
        }
        return dir;
    }
    int hashnum(int x, int y){
        return x+y*60001;
    }
    int robotSim(vector<int>& c, vector<vector<int>>& obstacles) {
        set<int>st;
        int x=0,y=0;
        string dir="+y";
        int ans=0;
        for(auto &val:obstacles){
            st.insert(hashnum(val[0],val[1]));
        }
        for(auto val:c){
            if(val==-1 || val==-2){
                dir=solve(dir,val);
                continue;
            }
            if(dir=="+x"){
                for(int i=0;i<val;i++){
                    if(st.find(hashnum(x+1,y))!=st.end()){
                        break;
                    }
                    x++;
                }
            }
            else if(dir=="-x"){
                for(int i=0;i<val;i++){
                    if(st.find(hashnum(x-1,y))!=st.end()){
                        break;
                    }
                    x--;
                }
            }
            else if(dir=="+y"){
                for(int i=0;i<val;i++){
                    if(st.find(hashnum(x,y+1))!=st.end()){
                        break;
                    }
                    y++;
                }
            }
            else if(dir=="-y"){
                for(int i=0;i<val;i++){
                    if(st.find(hashnum(x,y-1))!=st.end()){
                        break;
                    }
                    y--;
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};