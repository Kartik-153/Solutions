#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zerolithx;

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> current = nums;
        if (all_of(current.begin(), current.end(),
                   [](int x) { return x == 0; })) {
            zerolithx = current;
            return 0;
        }
        auto canMakeZero = [&](int k) -> bool {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diff[l] += val;
                if (r + 1 < n) {
                    diff[r + 1] -= val;
                }
            }
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += diff[i];
                if (total < current[i]) {
                    return false;
                }
            }
            return true;
        };
        int left = 0, right = queries.size(), ans = -1;
        bool midStateStored = false;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canMakeZero(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (!midStateStored && mid == (int)queries.size() / 2) {
                vector<int> diff(n + 1, 0);
                for (int i = 0; i < mid; i++) {
                    int l = queries[i][0], r = queries[i][1],
                        val = queries[i][2];
                    diff[l] += val;
                    if (r + 1 < n) {
                        diff[r + 1] -= val;
                    }
                }

                zerolithx = current;
                int total = 0;
                for (int i = 0; i < n; i++) {
                    total += diff[i];
                    zerolithx[i] = max(0, current[i] - total);
                }
                midStateStored = true;
            }
        }

        return ans;
    }
};
