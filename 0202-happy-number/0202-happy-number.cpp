class Solution {
    long long int digitSum(int n){
        long long int sum1 = 0;
        while(n){
            sum1 += (n % 10)*(n % 10);
            n = n / 10;
        }
        return sum1;
    }

public:
    bool isHappy(int n) {
        long long int firstCall = n;
        long long int nextCall = digitSum(n);
        while (firstCall != nextCall) {
            firstCall = digitSum(firstCall);
             nextCall = digitSum(digitSum(nextCall));
            if (firstCall == 1 || nextCall == 1) return true;
        }
        return firstCall == 1;
    }
};
