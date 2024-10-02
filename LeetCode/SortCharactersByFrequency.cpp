#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for(char ch : s) {
            counts[ch]++;
        }

        vector<pair<int, int>> sortedCharacters(counts.begin(), counts.end());

        sort(sortedCharacters.begin(), sortedCharacters.end(), 
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return b.second < a.second;
            });

        string sortedString = "";
        for(auto e: sortedCharacters) {
            sortedString += string(e.second, e.first);
        }
        return sortedString;
    }
};