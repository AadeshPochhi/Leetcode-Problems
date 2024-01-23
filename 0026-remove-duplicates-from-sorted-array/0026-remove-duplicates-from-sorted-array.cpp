class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int i=1,j=1,temp=nums[0];
        while(j<nums.size()){
            if(nums[j]==temp){
                j++;
            }
            else{
                nums[i]=nums[j];
                temp=nums[j];
                i++; j++;
                
            }
        }
        return i;
    }
};