class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        for(int i=1;i<n;i++){
            int newRow=i+1;
            vector<int>row;
            for(int j=0;j<newRow;j++){
                int val=1;
                if(j>0 && j<newRow-1) val=ans[i-1][j-1]+ans[i-1][j];
                row.push_back(val);
            }
            ans.push_back(row);
        }
        return ans;
    }
};