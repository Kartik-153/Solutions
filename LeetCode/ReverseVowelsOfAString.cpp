#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string str) {
        int n = str.size();
        int s = 0, e = n - 1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (s < e) {
            while (s < e && vowels.find(str[s]) == vowels.end()) {
                s++;
            }
            while (s < e && vowels.find(str[e]) == vowels.end()) {
                e--;
            }
            if (s < e) {
                swap(str[s], str[e]);
                s++;
                e--;
            }
        }
        return str;
    }
};
