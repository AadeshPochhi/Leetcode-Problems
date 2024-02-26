class Solution {
public:
    bool helper(vector<int>& weights, int days,int c){
        int daysNeeded=1,cL=0;
        for(int w:weights){
            cL+=w;
            if(cL>c)
            {daysNeeded++;
                cL=w;}
        }
        return daysNeeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int tL=0,mL=0;
        for(int w : weights){
            tL+=w;
            mL=max(w,mL);
        }
        int l=mL,h=tL;
        while(l<h){
            int mid=(l+h)/2;
            if(helper(weights,days,mid)){
                h=mid;
            }
            else
                l=mid+1;
            
        }
        return l;
    }
};