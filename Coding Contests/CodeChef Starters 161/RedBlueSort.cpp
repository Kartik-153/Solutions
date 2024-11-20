/**
*  जय सिया राम
*/

#include <bits/stdc++.h>
using namespace std;

#define IIN ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long int
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define rep(i, a, n) for(int i = a; i < n; i++)
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue <int>
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define mod 1000000007

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int C = 0;
    rep(i, 0, N) {
        cin >> P[i];
        if (P[i] == i + 1) {
            C++;
        }
    }

    if (C == N) {
        cout << N << "\n";
    } else if (C >= 1) {
        cout << (N - 1) << "\n";
    } else {
        if (N >= 2) {
            cout << (N - 2) << "\n";
        } else {
            cout << "0\n";
        }
    }
}
int32_t main() {
    IIN;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
