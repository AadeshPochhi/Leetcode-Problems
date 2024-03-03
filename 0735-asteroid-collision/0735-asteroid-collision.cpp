class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int a:asteroids){
            int flag=1;
            while(!s.empty() && (s.top()>0 && a<0)){
                if(abs(s.top())<abs(a)){
                    s.pop();
                    continue;
                }
                else if(abs(s.top())==abs(a)){
                    s.pop();
                }
                   flag=0;
                    break;
            }
            if(flag) s.push(a);
        }
        vector<int>ans(s.size());
            for(int i=ans.size()-1;i>=0;i--){
                ans[i]=s.top();
                s.pop();
            }
        return ans;
    }
};