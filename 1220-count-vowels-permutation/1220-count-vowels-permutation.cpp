class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000007;
        long a_count = 1, e_count = 1, i_count = 1, o_count = 1, u_count = 1;
        
        for (int i = 1; i < n; ++i) {
            long new_a = (e_count + i_count + u_count) % MOD;
            long new_e = (a_count + i_count) % MOD;
            long new_i = (e_count + o_count) % MOD;
            long new_o = i_count;
            long new_u = (i_count + o_count) % MOD;
            
            a_count = new_a;
            e_count = new_e;
            i_count = new_i;
            o_count = new_o;
            u_count = new_u;
        }
        
        long total = (a_count + e_count + i_count + o_count + u_count) % MOD;
        
        return (int)total;
    }
};