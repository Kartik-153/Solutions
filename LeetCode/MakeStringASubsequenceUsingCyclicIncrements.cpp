#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lenStr1 = str1.size(), lenStr2 = str2.size();

        for(int str1Index = 0; str1Index < lenStr1 && str2Index < lenStr2; ++str1Index) {
            if (str1[str1Index] == str2[str2Index] ||
                (str1[str1Index] + 1 == str2[str2Index]) ||
                (str1[str1Index] - 25 == str2[str2Index])) {
                str2Index++;
            }
        }
        return str2Index == lenStr2;
    }
};