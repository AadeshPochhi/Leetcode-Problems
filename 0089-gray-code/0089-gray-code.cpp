class Solution {
public:
    vector<int> grayCode(int n) {
        int mask=1<<n;
        vector<int> v(mask);
        
        for(int i=0;i<mask;i++){
            int t=i ^ (i>>1);
            v[i]=t;
        }
        return v;
    }
};