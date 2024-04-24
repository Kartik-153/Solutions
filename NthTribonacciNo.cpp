#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> F(100);
        F[0] = 0;
        F[1] = 1;
        F[2] = 1;
        for(int i = 3; i <= n; i++) {
            F[i] = F[i-3] + F[i-2] + F[i-1];
        }
        return F[n];
    }
};
