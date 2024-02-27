class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return true;
            if(!BSHelp(nums,l,nums[mid])){
                l++;
                continue;
            }
            bool pivot=existinF(nums,l,nums[mid]);
            bool targetin=existinF(nums,l,target);
            if(pivot^targetin){
                if(pivot){
                    l=mid+1;
                }
                else
                    h=mid-1;
            }
            else{
                if(nums[mid]<target)
                    l=mid+1;
                else
                    h=mid-1;
            }
            
        }
        return false;
    }
    bool BSHelp(vector<int>& nums,int start,int element){
        return nums[start]!=element;
    }
    bool existinF(vector<int>& nums,int start,int element){
        return nums[start]<=element;
    }
};