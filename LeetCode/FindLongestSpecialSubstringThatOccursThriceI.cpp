#include<bits/stdc++.h>
using namespace std;

class Solution {   // Brute force O(n^3)
public:
    int maximumLength(string s) {
        map<string, int> count;
        for (int start = 0; start < s.size(); start++) {
            string currString;
            for (int end = start; end < s.size(); end++) {
                if (currString.empty() || currString.back() == s[end]) {
                    currString.push_back(s[end]);
                    count[currString]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto i : count) {
            string str = i.first;
            if (i.second >= 3 && str.size() > ans)
                ans = str.size();
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};
