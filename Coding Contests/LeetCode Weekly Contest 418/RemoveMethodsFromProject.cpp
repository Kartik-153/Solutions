#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> susMethods;
        susMethods.insert(k);
        bool x = true;
        while (x) {
            x = false;
            for (const auto& invocation : invocations) {
                int a = invocation[0]; 
                int b = invocation[1];
                if (susMethods.count(a) && !susMethods.count(b)) {
                    susMethods.insert(b);
                    x = true; 
                }
            }
        }
        for (const auto& invocation : invocations) {
            int a = invocation[0];
            int b = invocation[1];
            if (!susMethods.count(a) && susMethods.count(b)) {
                return createArray(n);
            }
        }
        vector<int> remainingMethods;
        for (int i = 0; i < n; ++i) {
            if (!susMethods.count(i)) {
                remainingMethods.push_back(i);
            }
        }

        return remainingMethods;
    }

private:
    vector<int> createArray(int n) {
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = i;
        }
        return result;
    }
};