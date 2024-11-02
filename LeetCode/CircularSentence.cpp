#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while(ss >> word) {
            words.push_back(word);
        }

        int n = words.size();

        char last = words[n-1].back();

        for(int i = 0; i < n; i++) {
            if(words[i].front() != last) return false;
            last = words[i].back();
        }

        return true;
    }
};

class Solution { // regex solution
public:          // used only for splitting else rest of the solution remain same.
    bool isCircularSentence(string sentence) {
        regex wordRegex("[a-zA-Z]+");
        sregex_token_iterator iter(sentence.begin(), sentence.end(), wordRegex);
        sregex_token_iterator end;

        vector<string> words;
        while(iter != end) {
            words.push_back(*iter);
            ++iter;
        }

        if(words.size() == 1) {
            return words[0].front() == words[0].back();
        }

        for(int i = 0; i < words.size(); ++i) {
            int next = (i+1)%words.size();
            if(words[i].back() != words[next].front()) {
                return false;
            }
        }

        return true;
    }
};

class Solution {  // Best Solution.
public:
    bool isCircularSentence(string sentence) {
        for(int i = 0; i < sentence.size(); ++i) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1])
                return false;
        }

        return sentence[0] == sentence[sentence.size() - 1];
    }
};