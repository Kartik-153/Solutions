#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;

        int alEle = 1;
        int last = colors[0];

        for (int i = 1; i < n + k - 1; i++) {
            int idx = i % n;

            if (colors[idx] == last) {
                alEle = 1;
                last = colors[idx];
                continue;
            }
            alEle += 1;
            if (alEle >= k)
                res++;
            last = colors[idx];
        }
        return res;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        int left = 0;
        int right = 1;

        while (right < length) {
            if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
                continue;
            }

            right++;
            if (right - left < k)
                continue;

            result++;
            left++;
        }

        return result;
    }
};
