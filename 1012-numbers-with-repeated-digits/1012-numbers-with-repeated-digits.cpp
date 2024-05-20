class Solution {
public:

    long long dp[10][1<<10][2][2][2]; 

    long long solve(string & s , int index , int mask , int tight , int taken , int choose){
        
        if(index == s.size()) return choose; 
        if(dp[index][mask][tight][taken][choose] != -1) return dp[index][mask][tight][taken][choose]; 

        char k = '9'; 
        if(tight) k = s[index]; 

        long long ans = 0; 
        for(char c = '0' ; c <= k ; c++){
            int ele = c-'0'; 
            if((1<<ele) & (mask)) 
            ans += solve(s , index+1 , ( (mask) | (1<<ele)) , tight && (c == k) , 1 , 1); 
            else {
                if((c > '0') || (c == '0' && taken)){
                    ans += solve(s , index+1 , ( (mask) | (1<<ele)) , tight && (c == k) , 1 , choose); 
                }
                else ans += solve(s , index+1 , (mask) , tight && (c == k) , 0 , choose);
            }
        }
        return dp[index][mask][tight][taken][choose] =  ans;
    }
    int numDupDigitsAtMostN(int n) {

        memset(dp , -1 , sizeof(dp)); 
        string s = ""; 
        while(n){
            s += (n%10 + '0'); 
            n /= 10;
        }
        reverse(s.begin() , s.end()); 
        return solve(s , 0 , 0 , 1 , 0 , 0) ; 
    }
};