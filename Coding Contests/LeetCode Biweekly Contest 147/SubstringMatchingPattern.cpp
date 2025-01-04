#include<bits/stdc++.h>
using namespace std;

class Solution { // wrong answer
public:
    bool hasMatch(string s, string p) {
        int startPosition = p.find('*');
        string prefixStr = p.substr(0, startPosition);
        string suffixStr = p.substr(startPosition + 1);

        if(s.find(prefixStr) != string::npos && s.find(suffixStr) != string::npos)
            return true;
        return false;
    }
};



