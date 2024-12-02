#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream words(sentence);
        string currWord;
        int wordPosition = 1;

        while(words >> currWord) {
            if(currWord.size() >= searchWord.size() && 
                currWord.compare(0, searchWord.size(), searchWord) == 0) {
                return wordPosition;
            }
            wordPosition++;
        }

        return -1;
    }
};