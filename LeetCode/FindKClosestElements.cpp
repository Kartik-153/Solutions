#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int K, int X) {
        vector<int> windowOfKClosest;
        int idx = binarySearch(arr, X);
        int windowStart = idx;
        int windowEnd = idx + 1;
        int n = arr.size();

        for (int i = 0; i < K; i++) { // Two Pointer approach
            if (windowStart >= 0 && windowEnd < n) {    // Inside the range of the array
                int diffFromStart = abs(X - arr[windowStart]);   
                int diffFromEnd = abs(X - arr[windowEnd]);

                if (diffFromStart <= diffFromEnd) {
                    windowOfKClosest.push_back(arr[windowStart]);
                    windowStart--;
                } else {
                    windowOfKClosest.push_back(arr[windowEnd]);
                    windowEnd++;
                }
            } else if (windowStart >= 0) {
                windowOfKClosest.push_back(arr[windowStart]);
                windowStart--;
            } else if (windowEnd < n) {
                windowOfKClosest.push_back(arr[windowEnd]);
                windowEnd++;
            }
        }

        sort(windowOfKClosest.begin(), windowOfKClosest.end());
        return windowOfKClosest;
    }

private:
    int binarySearch(vector<int>& arr, int X) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == X) {
                return mid;
            }
            if (arr[mid] < X) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo > 0) {
            return lo - 1;
        }
        return lo;
    }
};
