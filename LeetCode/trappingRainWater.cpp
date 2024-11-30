#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;

        int l = 0, r = n - 1;
        int res = 0;
        int leftM = heights[l];
        int rightM = heights[r];

        while (l < r) {
            if(leftM < rightM) {
                l += 1;
                leftM = max(leftM, heights[l]);
                res += leftM - heights[l];
            }
            else {
                r -= 1;
                rightM = max(rightM, heights[r]);
                res+= rightM - heights[r];
            }
        }
        return res;
    }
};

