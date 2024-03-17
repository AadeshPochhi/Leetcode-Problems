class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=goal.length();
        int flag=0;
        for(int i=0;i<s.length();i++){
            if((s[i]==goal[0])&&(s.substr(i)==goal.substr(0,n-i)) && (s.substr(0,i)==goal.substr(n-i))) {
                flag=1;
                break;
            }
                
        }
        if(flag==1) return true;
        return false;
    }
};