#include<bits/stdc++.h>
using namespace std;


void solve(int n, int s) {
    vector<int> v;
    v.push_back(s);
    int xor_value = 0;
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) {
            v.push_back(i);
            xor_value ^= i;
        } else {
            int comp = s-i;
            v.push_back(comp);
            xor_value ^= comp;
        }
    }
    if(xor_value != 0) {
        cout << -1 << endl;
        v.clear();
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    int t = 0;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        solve(n,s);
    }
}