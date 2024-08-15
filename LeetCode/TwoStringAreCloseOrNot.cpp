#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool closeStrings(string word1, string word2) {
//         vector<int> w1(26,0), w2(26,0);
//         set<char> s1, s2;
//         for(char c: word1) {
//             w1[c-'a']++;
//             s1.insert(c);
//         }

//         for(char c: word2) {
//             w2[c-'a']++;
//             s2.insert(c);
//         }
//         sort(w1.begin(), w1.end());
//         sort(w2.begin(), w2.end());
//         return w1==w2 && s1==s2;
//     }
// };
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(char c:word1)
            w1[c-'a']++,w3[c-'a'] = 1;
    
        for(char c:word2)
            w2[c-'a']++,w4[c-'a'] = 1;
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&w3==w4;
    }
};
