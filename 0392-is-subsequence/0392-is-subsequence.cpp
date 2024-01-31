class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        int i=0,j=0,count=0;
        while(i<l1 && j<l2){
            if(s[i]==t[j]){
                i++; j++; count++;
            }
            else{
                j++;
            }
        }
        return count==s.length();
        
    }
};