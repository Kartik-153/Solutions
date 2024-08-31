#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            int l = max(firstList[i][0], secondList[j][0]);
            int u = min(firstList[i][1], secondList[j][1]);

            if (l <= u) {
                result.push_back({l, u});
            }
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};
