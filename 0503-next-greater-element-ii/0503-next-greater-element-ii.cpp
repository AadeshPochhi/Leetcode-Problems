class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>v(nums.size(),-1);
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=s.top()){
                s.pop();
            }
            if(!s.empty() && i<n){
                v[i]=s.top();
            }
            s.push(nums[i%n]);
        }
        return v;
    }
};