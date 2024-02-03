class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        if(l==h && nums[0]==target){
            return 0;
        }
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]<target){
                l=m+1;
            }
            else if(nums[m]>target){
                h=m-1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};