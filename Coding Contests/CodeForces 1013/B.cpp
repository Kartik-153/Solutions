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
#define all2(p)       p.rbegin(), p.rend()
#define double        long double
#define que_max       priority_queue <int>
#define print(a)      for(auto x : a) cout << x << " "; cout << endl;
#define print1(a)     for(auto x : a) cout << x.F << " " << x.S << endl;
#define mod           1000000007
 
void solve(int n, int x, vector<int> &v) {
    sort(all2(v));
    int ans = 0;
    int cur = 0;
    int l = 0;
    while(cur < n) {
        cur++;
        l++;
        if(l*v[cur-1] >= x) {
            ans++;
            l = 0;
        }
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
       solve(n, x, v);
    }
    return 0;
}
