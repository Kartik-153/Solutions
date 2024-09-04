#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        string s = "";
        cin >> s;
        map<char, int> m;
        for(int i = 0; i < 4*n; i++) {
            m[s[i]]++; 
        }
        int ans = 0;
        ans += min(n, m['A']);
        ans += min(n, m['B']);
        ans += min(n, m['C']);
        ans += min(n, m['D']);

        cout << ans << endl;

    }
    return 0;
}