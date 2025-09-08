#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll mod = 1e9;

void solve(ll n) {
    vector<ll> ans;
    ll d = 11;
    while (n >= d) {
        if (n % d == 0) {
            ans.push_back(n / d);
        }
        d = (d - 1) * 10 + 1;
    }
    
    if (ans.empty()) {
        cout << 0 << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}