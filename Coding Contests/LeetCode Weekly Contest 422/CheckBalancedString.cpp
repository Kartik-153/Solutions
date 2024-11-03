#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int sum1 = 0;
        int n = num.size();
        for(int i = 0; i < n; i = i + 2) {
            sum1 = sum1 + num[i] - '0';
        }

        int sum2 = 0;
        for(int i = 1; i < n; i = i + 2) {
            sum2 = sum2 + num[i] - '0';
        }

        return (sum1 == sum2) ? true : false;
        
    }
};