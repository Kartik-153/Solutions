/**
*  जय सिया राम
*/

#include <bits/stdc++.h>
using namespace std;

#define int           long long int
#define endl          "\n" 
#define pb            push_back
#define F             first
#define S             second
#define rep(i, a, n)  for(int i = a; i < n; i++)
#define all(p)        p.begin(), p.end()
#define double        long double
#define que_max       priority_queue <int>
#define print(a)      for(auto x : a) cout << x << " "; cout << endl;
#define print1(a)     for(auto x : a) cout << x.F << " " << x.S << endl;
#define mod           1000000007

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    int mn = A[0], mx = A[0];
    for(int x : A) {
        if(x < mn) mn = x;
        if(x > mx) mx = x;
    }
    int l = 0, r = mx - mn;
    
    if(r < 0) r = 0;
    
    while(l < r) {
        int mid = l + (r - l) / 2;
        int count = 1;
        int low = A[0] - mid;
        int high = A[0] + mid;
        rep(i, 1, N) {
            int new_low = A[i] - mid;
            int new_high = A[i] + mid;
            low = max(low, new_low);
            high = min(high, new_high);
            if(low > high) {
                count += 1;
                low = new_low;
                high = new_high;
            }
        }
        if(count <= K + 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
