class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> count(26,0);
        vector<int> l(26,-1);
        int maxn=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a';
            maxn=max(maxn,++count[ch]);
            l[ch]=i;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a';
            if(count[ch]==maxn && l[ch]==i){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};