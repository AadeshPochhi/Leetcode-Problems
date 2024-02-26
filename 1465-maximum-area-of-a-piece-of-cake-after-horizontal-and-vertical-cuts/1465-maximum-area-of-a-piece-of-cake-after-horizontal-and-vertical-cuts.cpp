class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        hC.push_back(0);
        hC.push_back(h);
        vC.push_back(0);
        vC.push_back(w);
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        int l=0,b=0;
        for(int i=1;i<hC.size();i++){
            l=max(l,hC[i]-hC[i-1]);
        }
        for(int i=1;i<vC.size();i++){
            b=max(b,vC[i]-vC[i-1]);
        }
        long long int mod = 1000000007;
        long long int res = l;
        res*=b;
        res%=mod;
        //res+=mod;res%=mod;
        return res;
    }
};