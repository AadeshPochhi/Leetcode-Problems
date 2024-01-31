class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
         int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && (nums[j]-nums[i])<diff){
                j++;
            }
            if(j!=n){
                if((nums[j]-nums[i])==diff){
                    int k=j+1;
                    while(k<n && (nums[k]-nums[j])<diff){
                        k++;
                    }
                    if(k!=n){
                        if((nums[k]-nums[j])==diff){
                        ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};