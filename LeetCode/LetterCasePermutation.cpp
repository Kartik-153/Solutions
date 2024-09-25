#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> permutations;
        permutations.push_back(s);

        for(int i = 0; i < s.length(); i++) {
            if(!isdigit(s[i])) {
                int n = permutations.size();

                for(int j = 0; j < n; j++) {
                    vector<char> chs(permutations[j].begin(), permutations[j].end());
                    
                    if(islower(chs[i])) {
                        chs[i] = toupper(chs[i]);
                    } else {
                        chs[i] = tolower(chs[i]);
                    }
                    permutations.push_back(string(chs.begin(), chs.end()));
                }
            }
        }
        return permutations;
    }
};