#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addbinary(string a, string b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) carry += a[i--] - '0';
            if(j >= 0) carry += a[j--] - '0';
            ans += carry%2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};