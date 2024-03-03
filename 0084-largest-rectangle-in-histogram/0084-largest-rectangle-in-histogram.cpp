class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && h[i]<=h[s.top()]){
                s.pop();
            }
            if(s.empty()){
                int width=i+1;
                ans[i]+=h[i]*width;
            }
            else{
                int width=i-s.top();
                ans[i]+=h[i]*(width);
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && h[i]<=h[s.top()]){
                s.pop();
            }
            if(s.empty()){
                int width=n-i;
                ans[i]+=h[i]*(width-1);
            }
            else{
                int width=s.top()-i;
                ans[i]+=h[i]*(width-1);
            }
            s.push(i);
        }
        return *max_element(ans.begin(),ans.end());
    }
};