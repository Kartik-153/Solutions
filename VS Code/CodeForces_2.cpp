#include <bits/stdc++.h>
using namespace std;

int penalty(string s, int n) {
    int count_minus = 0;
    int count_plus = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '+') {
            count_plus += 1;
        }
        if(s[i] == '-') {
            count_minus += 1;
        }
    }
    return abs(count_plus - count_minus);
}

int main() {
    int n = 0;
    cin >> n;
    while(n--) {
        int x = 0;
        cin >> x;
        string str;
        cin >> str;
        cout << penalty(str, x)<< endl;
    }
    return 0;
}