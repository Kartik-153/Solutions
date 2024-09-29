#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        if(k + 5 > word.size()) {
            return 0;
        }
        int res = 0;

        for(int i = 0; i < word.size(); i++) {
            unordered_set<char> vo;
            int consCnt = 0;
            for(int j = i; j < word.size(); j++) {
                char curr = word[j];
                if(isvowel(curr)) {
                    vo.insert(curr);
                } else {
                    consCnt+=1;
                }
                if(vo.size() == 5 && consCnt == k) {
                    res += 1;
                } 
                if(consCnt > k) {
                    break;
                }
            }    
        }
        return res;
    }

private:
    bool isvowel(char ch){ 
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'; 
    } 
};
