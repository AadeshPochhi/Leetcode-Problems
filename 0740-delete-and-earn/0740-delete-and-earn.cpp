class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        vector<int> ele;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=nums[i];
        }
        for(const auto& a:mp ){
            ele.push_back(a.first);
        }
        sort(ele.begin(), ele.end());
        int oneBack=mp[ele[0]];
        int twoBack=0;
        for(int i=1;i<ele.size();i++){
            int current=ele[i];
            int temp=oneBack;
            if(current==ele[i-1]+1){
                oneBack=max(oneBack,mp[current]+twoBack);
            }
            else
                oneBack+=mp[current];
            twoBack=temp;
            
        }
        return oneBack;
    }
};