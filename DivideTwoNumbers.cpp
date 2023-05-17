#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        sign = (dividend < 0) ^ (divisor < 0);
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = abs(dividend);
        long n = abs(divisor);

        long count = 0;
        while(m>=n) {
            m = m - n;
            count += 1;
        }
        if(sign) {
            count = -count;
        }
        if(count > pow(2,31) - 1) {
            return pow(2,31) - 1;
        }
        if(count < pow(-2,31)) {
            return pow(-2,31);
        }
        return count;
    }
};