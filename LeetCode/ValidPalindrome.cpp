#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool isNotAlnum(char c){
        return !isalnum(static_cast<unsigned char>(c));
    }
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str = s;
        reverse(str.begin(), str.end());
        if(str == s) {
            return true;
        }
        return false;
    }
};
