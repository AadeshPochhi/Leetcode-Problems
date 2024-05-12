class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();
        int i=0;
        while(i<n){
            while(dq.size() && dq.front()<i-k+1){
                dq.pop_front();
            }
            while(dq.size() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
            i++;
        }
        return ans;
    }
};