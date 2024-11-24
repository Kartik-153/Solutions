#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstringWithKdistinct(string str, int k) {
        int s = 0, maxLen = 0;
        unordered_map<char, int> charFreq;

        for(int e = 0; e < str.size(); e++) {
            char endChar = str[e];
            charFreq[endChar]++;

            while(charFreq.size() > k) {
                char startChar = str[s];
                charFreq[startChar]--;

                if(charFreq[startChar] == 0) {
                    charFreq.erase(startChar);
                }
                s++;
            }
            maxLen = max(maxLen, e - s + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution x;

    cout << x.longestSubstringWithKdistinct("araaci", 2) << "\n";
    cout << x.longestSubstringWithKdistinct("cbbebi", 3);
    return 0;
}