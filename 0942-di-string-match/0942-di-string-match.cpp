class Solution {
public:
    vector<int> diStringMatch(string s) {
        int a=0,b=s.length();
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                ans.push_back(a);
                a++;
            }
            if(s[i]=='D'){
                ans.push_back(b);
                b--;
            }
        }
        ans.push_back(a);
        return ans;
    }
};