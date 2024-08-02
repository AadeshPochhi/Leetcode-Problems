class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) return false;

        if((n-1)%2!=0) 
            return true; 
        return false; 
    }
};