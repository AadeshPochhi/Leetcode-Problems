class Solution {
public:
    int dp[21][5001];
    int fun(int idx, int n, int sum1, int sum2 , int maxSum, vector<int>& rods){
        if(sum1 > maxSum or sum2 > maxSum) return INT_MIN;
        
        if(idx >= n) { 
            return sum1 == sum2 ? sum1 : INT_MIN;
        }
        if(dp[idx][abs(sum1 - sum2)] != -1){
            return dp[idx][abs(sum1 - sum2)] == INT_MIN ? INT_MIN : dp[idx][abs(sum1 - sum2)] + max(sum1, sum2);
        }
        int op1 = fun(idx+1, n, sum1, sum2, maxSum, rods);
        int op2 = fun(idx+1, n, sum1+rods[idx] , sum2, maxSum, rods);
        int op3 = fun(idx+1, n, sum1, sum2+rods[idx], maxSum, rods);
        
        if(max(op1, max(op2, op3)) == INT_MIN) return dp[idx][abs(sum1 - sum2)] = INT_MIN;
        dp[idx][abs(sum1 - sum2)] = max(op1, max(op2, op3)) - max(sum1, sum2);
        return dp[idx][abs(sum1 - sum2)] + max(sum1, sum2);
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        memset(dp, -1, sizeof(dp));
        int maxSum = accumulate(rods.begin(), rods.end(), 0) / 2;
        return max(0, fun(0, n, 0, 0, maxSum, rods));
    }
};