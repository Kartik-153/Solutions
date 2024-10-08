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

class Solution2 {
public:
    string frequencySort(string s) {
        map<char, int> count_map;
        for (char st : s) {
            count_map[st] += 1;
        }
        auto comp = [&count_map](const char a, const char b) {
            return count_map[a] < count_map[b];
        };
        priority_queue<char, vector<char>, decltype(comp)> heap(comp);

        for (auto p : count_map) {
            heap.push(p.first);
        }
        string res = "";
        while (!heap.empty()) {
            char temp = heap.top();
            heap.pop();
            res.append(count_map[temp], temp);
        }

        return res;
    }
};