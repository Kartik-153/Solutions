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
 
void solve(int n, vector<int>& v) {
    int ans = 0;
    vector<int> freq(10);
    for(int i = 0; i < n; i++) {
        freq[v[i]]++;
        if(freq[0] >= 3 && freq[1] && freq[2] >=2 && freq[3] && freq[5]) {
            if(!ans) {
                ans = i + 1;
            }
        }
    }
    cout << ans << '\n';
} 
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve(n, v);
    }

    return 0;
}