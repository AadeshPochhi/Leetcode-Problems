class Solution {
public:
    string process(string s){
        stack<char> sk;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!sk.empty()){
                    sk.pop();
                }
            }
            else{
                sk.push(s[i]);
            }
        }
        while(!sk.empty()){
            str+=sk.top();
            sk.pop();
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        return process(s)==process(t);
    }
};