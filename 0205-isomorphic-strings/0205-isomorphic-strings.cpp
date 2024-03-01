class Solution {
public:
    string transform(string s){
        stringstream builder;
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(mp.find(ch)==mp.end()){
                mp[ch]=i;
                builder<<i;
                builder<<" ";
            }
            else{
                builder<<mp[ch]<<" ";
            }
        }
        return builder.str();
    }
    bool isIsomorphic(string s, string t) {
       return transform(s)==transform(t);
    }
};