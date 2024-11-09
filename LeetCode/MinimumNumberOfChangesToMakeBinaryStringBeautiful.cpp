#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minChanges(string s) {
        char currentChar = s[0];
        int consecutiveCount = 0;
        int minChangesRequired = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == currentChar) {
                consecutiveCount += 1;
                continue;
            }

            if (consecutiveCount % 2 == 0) {
                consecutiveCount = 1;
            } else {
                consecutiveCount = 0;
                minChangesRequired += 1;
            }

            currentChar = s[i];
        }

        return minChangesRequired;
    }
};

class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired = 0;

        // Check pairs of characters (i, i+1) with step size 2
        for (int i = 0; i < s.length(); i += 2) {
            // If characters in current pair don't match,
            // we need one change to make them equal
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }

        return minChangesRequired;
    }
};