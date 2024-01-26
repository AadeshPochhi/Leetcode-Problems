class Solution {
public:
    int atMostK(vector<int>&a, int k){
        int l=0,r=-1;
        int ans=0;
        map<int,int>mp;
        int n=a.size();
        while(l<n){
            if(r<l){
                r=l-1;
            }
            while(r+1<n && ((mp.size() + (mp.find(a[r+1])==mp.end()))<=k)){
                mp[a[r+1]]++;
                r++;
            }
            ans+=r-l+1;
            mp[a[l]]--;
            if(mp[a[l]]==0){
                mp.erase(a[l]);
            }
            l++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums,k-1);
    }
};