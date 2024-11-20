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
#define rep(i,a,n)    for(int i = a; i < n; i++)
#define all(p)        p.begin(), p.end()
#define double        long double
#define que_max       priority_queue <int>
#define print(a)      for(auto x : a) cout << x << " "; cout << endl;
#define print1(a)     for(auto x : a) cout << x.F << " " << x.S << endl;
#define mod           1000000007
 
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);

    rep(i, 0, N) {
        cin >> A[i];
    }
    rep(i, 1, N-1) {
        if (A[i-1] + A[i+1] == 4) {
            A[i] = 4 - A[i];
        }
    }
    int sum = 0;
    rep(i, 0, N) {
        sum += A[i];
    }
    cout << sum << endl;
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