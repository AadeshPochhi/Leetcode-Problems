class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> numbers(n, false);
        for (int p = 2; p <= std::sqrt(n); ++p) {
            if (!numbers[p]) {
                for (int j = p * p; j < n; j += p) {
                    numbers[j] = true;
                }
            }
        }
        int numberOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            if (!numbers[i]) {
                ++numberOfPrimes;
            }
        }
        
        return numberOfPrimes;
    }
};