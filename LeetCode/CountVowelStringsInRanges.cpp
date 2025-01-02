#include<bits/stdc++.h>
using namespace std;

class Solution { // Brute force - TLE
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (auto& query : queries) {
            int l = query[0], r = query[1];
            int currSum = 0;

            for (int i = l; i <= r; i++) {
                int currStrLen = words[i].size();
                if (vowels.find(words[i][0]) != vowels.end() &&
                    vowels.find(words[i][currStrLen - 1]) != vowels.end()) {
                    currSum += 1;
                }
            }
            ans.push_back(currSum);
        }

        return ans;
    }
};

class Solution { // Prefix Sum
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (vowels.count(word[0]) && vowels.count(word[word.size() - 1])) sum += 1;
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
        }
        return ans;
    }
};
