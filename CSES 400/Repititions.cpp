#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    int cur = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1])  cur++;
        else                cur = 1;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;   
}