class Solution {
public: 
    vector<string> ans;
    void backtrack(string current, int open, int close, int n){
        if(open == n && close == n && open == close){
            ans.push_back(current);
        }
        if(open<n){
            backtrack(current+'(',open+1,close,n);
        }
        if(open>close){
            backtrack(current+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;
    }
};