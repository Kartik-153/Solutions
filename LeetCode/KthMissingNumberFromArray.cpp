#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (arr[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};

class Solution2 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }
};