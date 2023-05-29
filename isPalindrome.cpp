#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = 0;
        int ans = 0;
        while(x > 0) {
            temp = x % 10;
            ans = ans * 10 + temp;
            x = x / 10;
        }
        if(ans == x) { 
            return 1;
        }    
        else {
            return 0;
        }    
    }
};