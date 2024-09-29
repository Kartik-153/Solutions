#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while( word.size() < k) {
            string gen = genStr(word);
            word += gen;

        }
        return word[k - 1];
    }

private:
    string genStr(string word) {
        string res = "";
        for(char c: word) {
            char ch = c;
            ch += 1;
            res += ch;
        }
        return res;
    }
};