class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums.size() || nums[i]<=0){
                nums[i]=nums.size()+1;
            }
        }
        for(int i=0; i<nums.size(); i++){
    if(nums[i] > 0 && nums[i] <= nums.size()){
        int pos = nums[i] - 1;
        if(nums[pos] > 0){
            nums[i] = nums[pos];
            nums[pos] = -1; // Mark as visited
            i--; // Revisit the current index after the swap
        }
    }
}
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                return (i+1);
        }
        return (nums.size()+1);
    }
};