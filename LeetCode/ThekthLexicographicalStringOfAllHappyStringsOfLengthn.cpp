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

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if(k > total) return "";
        string res(n, 'a');
        unordered_map<char, char> nextSmall = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreat = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
        
        int startA = 1;
        int startB = startA + (1 << (n-1));
        int startC = startB + (1 << (n-1));

        if(k < startB) {
            res[0] = 'a';
            k -= startA;
        } else if(k < startC) {
            res[0] = 'b';
            k -= startB;
        } else {
            res[0] = 'c';
            k -= startC;
        }

        for(int i = 1; i < n; i++) {
            int mid = (1 << (n-i-1));
            if(k < mid) {
                res[i] = nextSmall[res[i-1]];
            } else {
                res[i] = nextGreat[res[i-1]];
                k -= mid;
            }
        }
        return res;
    }
};