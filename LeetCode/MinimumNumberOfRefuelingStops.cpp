#include <bits/stdc++.h>
using namespace std;

class Solution { // DP Solution
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int totalFuel = target;
        int n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++) {
            for (int t = i; t >= 0; t--) {
                if (dp[t] >= stations[i][0]) {
                    dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target)
                return i;
        }
        return -1;
    }
};

class Solution { // Heap Solution
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int currmax = startFuel;
        int count = 0;
        int i = 0;
        priority_queue<int> pq;
        while (currmax < target) {
            while (i < stations.size() and stations[i][0] <= currmax) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty())
                return -1;
            currmax += pq.top();
            pq.pop();
            count++;
        }
        return count++;
    }
};