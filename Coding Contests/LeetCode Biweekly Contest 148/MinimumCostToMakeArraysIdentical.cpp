#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        int n = a.size();
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += abs(a[i] - b[i]);
        }

        if (n > 1) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            long long currCost = 0;
            for (int i = 0; i < n; i++) {
                currCost += abs(a[i] - b[i]);
            }
            currCost += k;
            return min(tmp, currCost);
        }
        return tmp;
    }
};
