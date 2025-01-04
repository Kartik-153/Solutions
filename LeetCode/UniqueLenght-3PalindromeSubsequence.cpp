#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s)
            letters.insert(c);

        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    j = k;
                }
            }
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            ans += between.size();
        }
        return ans;
    }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};
