#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        if (n == 0)
            return 0;
        int res = 0;

        while (n) {
            res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};