class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> sumCount(target + 1);
        sumCount[0] = 1;
        int sz = nums.size();
        for(int sum = 1; sum <= target; sum++){
            for(int indx = 0; indx < sz; indx++){
                if(nums[indx] <= sum){
                    sumCount[sum] = (sumCount[sum] + sumCount[sum-nums[indx]]);
                }
            }
        }
        return sumCount[target];
    }
};