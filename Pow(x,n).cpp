#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) { // Time Complexity - O(log(n))
        if (n == numeric_limits<int>::min()) {
            return 1 / (pow(x, numeric_limits<int>::max()) * x);
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double result = 1;
        double current_product = x;

        while (n > 0) {
            if ((n&1) != 0) {
                result *= current_product;
            }
            current_product *= current_product;
            n=n>>1;
        }

        return result;
    }
};
