class Solution {
    int dp[12][302];
    public:
    int minDifficulty(vector<int>& arr, int day) {
        int n = arr.size();
        
        if(n<day) return -1;
        for(int i=0;i<=day;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = 1e6; 
            }
        } 
        for(int i=0;i<n;i++)
        { 
            dp[1][i] = *std::max_element(arr.begin()+i,arr.begin()+n);
        }
        for(int d= 2;d<=day;d++){
            for(int i=0;i<n;i++){
                if(n-i<d){
                    dp[d][i] = 1e6;
                    continue;
                }
                for(int j=i;j<n;j++){
                    dp[d][i] = min(dp[d][i],
                                   *std::max_element(arr.begin()+i,arr.begin()+j+1)
                                   +dp[d-1][j+1]);
                }
            }
        }
        return dp[day][0];
    }
};