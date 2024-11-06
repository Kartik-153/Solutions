#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int pos = 0;

        while(pos < word.size()) {
            int consCnt = 0;

            char currentChar = word[pos];

            while(pos < word.size() && consCnt < 9 && word[pos] == currentChar) {
                consCnt++;
                pos++;
            }

            comp += to_string(consCnt) + currentChar;
        }

        return comp;
    }
};