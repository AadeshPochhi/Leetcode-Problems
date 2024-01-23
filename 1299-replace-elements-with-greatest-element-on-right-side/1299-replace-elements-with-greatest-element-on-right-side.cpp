class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size()==1) return {-1};
        vector<int>ans;
        ans.push_back(-1);
        int max=INT_MIN;
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i]>=max){
                max=arr[i];
                ans.push_back(max);
            }
            else{
                ans.push_back(max);
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};