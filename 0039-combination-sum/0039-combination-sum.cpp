class Solution {
public:
    void solve(vector<int>& c,int s,int t,vector<int>&path,vector<vector<int>> &res){
        if(t==0){
            res.push_back(path);
            return;
        }
        if(t<0){
            return;
        }
        for(int i=s;i<c.size();i++){
            path.push_back(c[i]);
            solve(c,i,t-c[i],path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int>path;
        sort(c.begin(),c.end());
        solve(c,0,t,path,res);
        return res;
    }
};