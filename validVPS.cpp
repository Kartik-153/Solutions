#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxSum = 0;
        for(char c: s) {
            if(c=='(') {
                cnt++;
                if(maxSum < cnt) 
                maxSum = cnt;
            } 
            else if(c==')') {
                cnt--;
            }
        }
        return maxSum;
    }
};