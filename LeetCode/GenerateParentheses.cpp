#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string path, int openN, int closedN, int n) {
        if(openN == n && closedN == n) {
            res.push_back(path);
            return;
        }
        if(openN < n) {
            backtrack(res, path + "(", openN + 1, closedN, n);
        }

        if(closedN < openN) {
            backtrack(res, path + ")", openN, closedN + 1, n);
        }
    }
};