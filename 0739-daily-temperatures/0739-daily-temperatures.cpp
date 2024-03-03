class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int>ans(t.size());
        for(int i=0;i<t.size();i++){
            while(!s.empty() && (t[s.top()]<t[i])){
                int idx=s.top();
                ans[idx]=i-idx;
                s.pop();
            }
            s.emplace(i);
        }
        return ans;
    }
};