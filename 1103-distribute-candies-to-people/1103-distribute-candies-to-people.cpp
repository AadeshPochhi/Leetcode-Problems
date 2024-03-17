class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int t=1;
        int i=0;
        while(candies>0){
            if(i==num_people) i=0;
            if(t<candies){
                ans[i]+=t;
                candies-=t;
                t++; i++;
            }
            else{
                ans[i]+=candies;
                candies=0;
                break;
            }
        }
        return ans;
    }
};