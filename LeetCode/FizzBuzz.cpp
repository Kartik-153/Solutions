#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
                res.push_back("FizzBuzz");
            else if ((i + 1) % 3 == 0)
                res.push_back("Fizz");
            else if ((i + 1) % 5 == 0)
                res.push_back("Buzz");
            else {
                string s = to_string(i + 1);
                res.push_back(s);
            }
        }
        return res;
    }
};