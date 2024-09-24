#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct CompareStart {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first; // Max-heap for start times
        }
    };

    struct CompareEnd {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first; // Max-heap for end times
        }
    };

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Priority queues for max-heaps (start times and end times)
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareStart>
            maxStartHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareEnd>
            maxEndHeap;

        vector<int> res(n, -1); // Initialize result array to -1

        // Populate the heaps with intervals and their original indices
        for (int i = 0; i < n; i++) {
            maxStartHeap.push({intervals[i][0], i});
            maxEndHeap.push({intervals[i][1], i});
        }

        // Process intervals based on max end times
        for (int i = 0; i < n; i++) {
            // Get the interval with the highest end
            pair<int, int> topEndPair = maxEndHeap.top();
            int topEnd = topEndPair.first;
            int endIndex = topEndPair.second;
            maxEndHeap.pop(); // Remove the interval with the highest end

            res[endIndex] =
                -1; // Default to -1 if no valid next interval is found

            if (!maxStartHeap.empty() && maxStartHeap.top().first >= topEnd) {
                // Get the start time that is the closest but greater than or
                // equal to the current end
                pair<int, int> topStartPair = maxStartHeap.top();
                int topStart = topStartPair.first;
                int startIndex = topStartPair.second;

                while (!maxStartHeap.empty() &&
                       maxStartHeap.top().first >= topEnd) {
                    tie(topStart, startIndex) = maxStartHeap.top();
                    maxStartHeap.pop();
                }

                res[endIndex] = startIndex;

                // Put the start interval back as it could be the next interval
                // for other intervals
                maxStartHeap.push({topStart, startIndex});
            }
        }

        return res;
    }
};
