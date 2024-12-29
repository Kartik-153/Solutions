#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
        vector<vector<int>> charFrequency(words[0].size(), vector<int>(26, 0));

        // Store the frequency of every character at every index.
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[0].size(); j++) {
                int character = words[i][j] - 'a';
                charFrequency[j][character]++;
            }
        }
        return getWords(words, target, 0, 0, dp, charFrequency);
    }

private:
    long getWords(vector<string>& words, string& target, int wordsIndex,
                  int targetIndex, vector<vector<int>>& dp,
                  vector<vector<int>>& charFrequency) {
        if (targetIndex == target.size())
            return 1;
        if (wordsIndex == words[0].size() ||
            words[0].size() - wordsIndex < target.size() - targetIndex)
            return 0;

        if (dp[wordsIndex][targetIndex] != -1)
            return dp[wordsIndex][targetIndex];

        long countWays = 0;
        int curPos = target[targetIndex] - 'a';
        // Don't match any character of target with any word.
        countWays += getWords(words, target, wordsIndex + 1, targetIndex, dp,
                              charFrequency);
        // Multiply the number of choices with getWords and add it to count.
        countWays += charFrequency[wordsIndex][curPos] *
                     getWords(words, target, wordsIndex + 1, targetIndex + 1,
                              dp, charFrequency);

        return dp[wordsIndex][targetIndex] = countWays % 1000000007;
    }
};

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize a DP table.
        vector<vector<long>> dp(wordLength + 1,
                                vector<long>(targetLength + 1, 0));

        // Base case: There is one way to form an empty target string.
        for (int currWord = 0; currWord <= wordLength; ++currWord) {
            dp[currWord][0] = 1;
        }

        // Step 3: Fill the DP table.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // Carry over the previous value (not using this index of
                // "words").
                dp[currWord][currTarget] = dp[currWord - 1][currTarget];

                // Add ways using the current index of "words" if the characters
                // match.
                int curPos = target[currTarget - 1] - 'a';
                dp[currWord][currTarget] +=
                    (charFrequency[currWord - 1][curPos] *
                     dp[currWord - 1][currTarget - 1]) %
                    MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }

        // Step 4: The result is in dp[wordLength][targetLength].
        return dp[wordLength][targetLength];
    }
};

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize two DP arrays: prev and curr.
        vector<long> prevCount(targetLength + 1, 0);
        vector<long> currCount(targetLength + 1, 0);

        // Base case: There is one way to form an empty target string.
        prevCount[0] = 1;

        // Step 3: Fill the DP arrays.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            // Copy the previous row into the current row for DP.
            currCount = prevCount;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // If characters match, add the number of ways.
                int curPos = target[currTarget - 1] - 'a';
                currCount[currTarget] += (charFrequency[currWord - 1][curPos] *
                                          prevCount[currTarget - 1]) %
                                         MOD;
                currCount[currTarget] %= MOD;
            }
            // Move current row to previous row for the next iteration.
            prevCount = currCount;
        }

        // Step 4: The result is in prev[targetLength].
        return currCount[targetLength];
    }
};
