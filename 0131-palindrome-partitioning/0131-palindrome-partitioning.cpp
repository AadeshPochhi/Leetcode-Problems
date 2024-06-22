class Solution {
public:
    bool check(string& sub){
        int l=sub.size();
        if(l==1) return true;
        int s=0,e=l-1;
        while(s<e){
            if(sub[s]!=sub[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    void solve(int i, int n, string& s, vector<string>&p, vector<vector<string>>&ans){
        if(i==n) ans.push_back(p);
        for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            if(check(sub)){
                p.push_back(sub);
                solve(j+1,n,s,p,ans);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>p;
        int i=0,n=s.size();
        solve(i,n,s,p,ans);
        return ans;
    }
};