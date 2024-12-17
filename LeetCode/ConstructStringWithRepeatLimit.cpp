#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currCharIndex = 25;
        while (currCharIndex >= 0) {
            if (freq[currCharIndex] == 0) {
                currCharIndex--;
                continue;
            }

            int use = min(freq[currCharIndex], repeatLimit);
            result.append(use, 'a' + currCharIndex);
            freq[currCharIndex] -= use;

            if (freq[currCharIndex] > 0) {
                int smallerCharIndex = currCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0)
                    smallerCharIndex--;

                if (smallerCharIndex < 0)
                    break;
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }
        return result;
    }
};

class Solution {
public:
    string repeatLimitedString(string s, int repeatedLimit) {
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for(auto& [ch, count]: freq) {
            maxHeap.push(ch);
        }

        string result;
        while(!maxHeap.empty()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = max(count, repeatedLimit);
            result.append(use, ch);
            freq[ch]-=use;

            if(freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if(freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }
                maxHeap.push(ch);
            }
        }
        return result;
    }
};