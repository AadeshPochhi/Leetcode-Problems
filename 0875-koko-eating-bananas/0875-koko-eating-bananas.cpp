class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1,hi=*max_element(piles.begin(),piles.end());
        int var;
        while(l<=hi){
            long long mid=l+(hi-l)/2;
            long long hourspent=0;
            
            for(long long pile:piles){
                if(pile%mid==0) var=0;
                else var=1;
                hourspent+=(pile/mid)+var;
            }
            if(hourspent>h){
                l=mid+1;
            }
            else
                hi=mid-1;
        }
        return l;
    }
};