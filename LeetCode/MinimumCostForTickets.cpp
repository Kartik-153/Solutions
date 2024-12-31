#include<bits/stdc++.h>
using namespace std;

class Solution { // top down DP
public:
    unordered_set<int> isTravelNeeded;

    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs,
              int currDay) {
        if (currDay > days[days.size() - 1]) {
            return 0;
        }

        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }
        if (dp[currDay] != -1) {
            return dp[currDay];
        }

        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);

        for (int day : days) {
            isTravelNeeded.insert(day);
        }

        return solve(dp, days, costs, 1);
    }
};

class Solution { // Bottom-Up DP
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);

        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] =
                    min({dp[day - 1] + costs[0], dp[max(0, day - 7)] + costs[1],
                         dp[max(0, day - 30)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};
