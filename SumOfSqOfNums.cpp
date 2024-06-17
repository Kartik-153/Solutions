#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int l = 0;
        long long int h = static_cast<long long int>(sqrt(c));

        while (l <= h) {
            long long int currSum = l * l + h * h;
            if (currSum == c)
                return true;
            else if (currSum < c)
                l++;
            else
                h--;
        }
        return false;
    }
};
