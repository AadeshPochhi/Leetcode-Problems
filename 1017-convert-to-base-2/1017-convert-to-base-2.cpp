class Solution {
public:
    string baseNeg2(int N) {
        string res = "";
        while (N) {
            res = to_string(N & 1) + res;  
            N = -(N >> 1);  
        }
        return res.empty() ? "0" : res; 
    }
};