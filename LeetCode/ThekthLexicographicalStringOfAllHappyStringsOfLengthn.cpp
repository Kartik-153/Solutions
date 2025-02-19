#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        string currString = "";
        vector<string> happy;
        generateString(n, currString, happy);
        if (happy.size() < k)
            return "";
        sort(happy.begin(), happy.end());
        return happy[k - 1];
    }

private:
    void generateString(int n, string currentString, vector<string>& happy) {
        if (currentString.size() == n) {
            happy.push_back(currentString);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (currentString.size() > 0 && currentString.back() == ch)
                continue;

            generateString(n, currentString + ch, happy);
        }
    }
};

