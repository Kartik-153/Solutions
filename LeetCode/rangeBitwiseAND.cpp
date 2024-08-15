#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int msbPos(int n) {
        int msb = -1;
        while(n) {
            n = n >> 1;
            msb++;
        }
        return msb;
    }

    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        while(left && right) {
            int msb_p1 = msbPos(left);
            int msb_p2 = msbPos(right);
            if(msb_p1 != msb_p2) {
                break;
            }
            int msb_val = (1<<msb_p1);
            res = res + msb_val;
            left = left - msb_val;
            right = right - msb_val;
        }
        return res;
    }
};
