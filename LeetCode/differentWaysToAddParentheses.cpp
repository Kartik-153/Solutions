#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

    // Base case: if the expression string is a number, parse and add it to result
    bool isNumber = true;
    for (char c : expression) {
        if (!isdigit(c)) {
            isNumber = false;
            break;
        }
    }

    if (isNumber) {
        result.push_back(stoi(expression));
    } else {
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // If the character is not a digit (i.e., it's an operator)
            if (!isdigit(c)) {
                vector<int> leftParts = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightParts = diffWaysToCompute(expression.substr(i + 1));

                for (int l = 0; l < leftParts.size(); l++) {
                    for (int r = 0; r < rightParts.size(); r++) {
                        int part1 = leftParts[l];
                        int part2 = rightParts[r];

                        if (c == '+') {
                            result.push_back(part1 + part2);
                        } else if (c == '-') {
                            result.push_back(part1 - part2);
                        } else if (c == '*') {
                            result.push_back(part1 * part2);
                        }
                    }
                }
            }
        }
    }
    return result;
    }
};

class Solution2 {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return results;

        // Base case: if the string is a single character, treat it as a number
        // and return it
        if (expression.length() == 1) {
            results.push_back(stoi(expression));
            return results;
        }

        // If the string has only two characters and the first character is a
        // digit, parse it as a number
        if (expression.length() == 2 && isdigit(expression[0])) {
            results.push_back(stoi(expression));
            return results;
        }

        // Recursive case: iterate through each character
        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression[i];

            // Skip if the current character is a digit
            if (isdigit(currentChar)) continue;

            // Split the expression into left and right parts
            vector<int> leftResults =
                diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults =
                diffWaysToCompute(expression.substr(i + 1));

            // Combine results from left and right parts
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    // Perform the operation based on the current character
                    switch (currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.push_back(computedResult);
                }
            }
        }

        return results;
    }
};