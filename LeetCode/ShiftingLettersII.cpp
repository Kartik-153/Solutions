#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(n, 0);
        for (auto shift : shifts) {
            if (shift[2] == 1) {
                diffArray[shift[0]]++;
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]--;
                }
            } else {
                diffArray[shift[0]]--;
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]++;
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;
        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) % 26;
            if (numberOfShifts < 0)
                numberOfShifts += 26;
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};

class Solution {  // Prefix Sum Code
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> prefix(n + 1, 0); 

        for (auto &shift : shifts) {
            int a = shift[0];
            int b = shift[1];
            int c = shift[2];
            prefix[a] += (2 * c - 1);
            prefix[b + 1] -= (2 * c - 1);
        }


        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift = (currentShift + prefix[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift + 26) % 26; 
        }

        return s;
    }
};
