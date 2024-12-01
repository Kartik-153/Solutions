#include<bits/stdc++.h>
using namespace std;

class Solution {  // Two Pointers
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
class Solution { // Using memoization
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n < 3) return 0;
        vector<int> maxL(n), maxR(n);
        int result = 0;
        maxL[0] = heights[0];
        for (int i = 1; i < n; i++) 
            maxL[i] = max(maxL[i - 1], heights[i]);
        maxR[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            maxR[i] = max(maxR[i + 1], heights[i]);
        for (int i = 0; i < n; i++) 
            result += max(0, min(maxL[i], maxR[i]) - heights[i]);
        return result;
    }
};
