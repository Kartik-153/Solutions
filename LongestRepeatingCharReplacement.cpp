#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26);
        int maxcnt = 0;
        int i = 0;
        int j = 0;
        int result = 0;

        while(j < s.length()) {
            cnt[s[j] - 'A']++;
            maxcnt = max(maxcnt, cnt[s[j] - 'A']);

            if(j - i + 1 - maxcnt > k) {
                cnt[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};

