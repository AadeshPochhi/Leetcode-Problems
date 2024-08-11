class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int c=nums[0];
        for(auto num:nums){
            if(abs(num)<abs(c)){
                c=num;
            }
        }
        if(c<0 && find(nums.begin(),nums.end(),abs(c))!=nums.end()){
            return abs(c);
        }
        return c;
    }
};