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
 
void solve(int n) {
    vector<int> v(2*n);
    rep(i, 0, 2*n) {
        cin >> v[i];
    }

    map<int, int> mp;
    rep(i, 0, 2*n) {
        mp[v[i]]++;
    }
    int a = 0, b = 0, c = 0;
    int ans = 0, m;

    for(auto &it: mp) {
        m = it.second;
        if(m&1) {
            a+=1;
        } else {
            if(m % 4 == 0) {
                b+=1;
            } else if(m % 4 == 2) {
                c+=1;
            }
        }
    }

    if(a == 0 && (b & 1)) { // {4,4,4,4,5,5,5,5,8,8,8,8} case
        cout << 2*(c+b) - 2; 
    } else {
        cout << a + 2*(b+c);
    }
    cout << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
        while(t--) {
            int n = 0;
            cin >> n;
           solve(n);
    }
    return 0;
}
