#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool compare(const string& a, const string& b) { return a + b > b + a; }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaryStrings;

        for (int num : nums) {
            binaryStrings.push_back(toBinary(num));
        }
        sort(
            binaryStrings.begin(), binaryStrings.end(),
            [this](const string& a, const string& b) { return compare(a, b); });
            
        string concatenatedBinary = "";
        for (string binary : binaryStrings) {
            concatenatedBinary += binary;
        }

        int result = stoi(concatenatedBinary, nullptr, 2);

        return result;
    }

private:
    string toBinary(int num) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary == "" ? "0" : binary;
    }
};
