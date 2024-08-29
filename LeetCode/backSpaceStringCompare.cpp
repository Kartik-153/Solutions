#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string str1, string str2) {
        // Use two pointers to compare the strings
        int pointerOne = str1.length() - 1;
        int pointerTwo = str2.length() - 1;

        while (pointerOne >= 0 || pointerTwo >= 0) {
            int i = getNextChar(str1, pointerOne);
            int j = getNextChar(str2, pointerTwo);

            if (i < 0 && j < 0) {
                // Reached the end of both strings
                return true;
            }
            if (i < 0 || j < 0) {
                // Reached the end of one string
                return false;
            }
            if (str1[i] != str2[j]) {
                // Check if the characters are equal
                return false;
            }
            pointerOne = i - 1;
            pointerTwo = j - 1;
        }
        return true;
    }

private:
    int getNextChar(const string& str, int index) {
        int backspaceCount = 0;
        while (index >= 0) {
            if (str[index] == '#') {
                // Found a backspace character
                backspaceCount++;
            } else if (backspaceCount > 0) {
                // A non-backspace character
                backspaceCount--;
            } else {
                break;
            }
            // Skip a backspace or valid character
            index--;
        }
        return index;
    }
};