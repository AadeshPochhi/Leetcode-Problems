class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }


        int maxidx=idx;
        int maxval=1e9;
        for(int i=idx+1;i<n;i++){
            if(nums[i]>nums[idx]&&nums[i]<=maxval){
                maxval=nums[i];
                maxidx=i;
            }
        }

        swap(nums[maxidx],nums[idx]);
        reverse(nums.begin()+idx+1,nums.end());

    }
};