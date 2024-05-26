class Solution {
public:
    void solve(int start,int last,vector<int>& candidates,vector<int>& cur,int cs,int target,vector<vector<int>>& ans){
        if(cs==target){
            ans.push_back(cur);
            return;
        }
        if(start == candidates.size()){
            if(cs==target) ans.push_back(cur);
            return;
        }
        for(int i=start;i<=last;i++){
            if(i && i>start &&candidates[i]==candidates[i-1]) continue;
            if(cs+candidates[i]<=target){
            cur.push_back(candidates[i]);
            solve(i+1,last,candidates,cur,cs+candidates[i],target,ans);
            cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;
        solve(0,candidates.size()-1,candidates,cur,0,target,ans);
        return ans;
    }
};