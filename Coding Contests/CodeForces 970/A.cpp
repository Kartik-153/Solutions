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
    int a, b;
    cin >> a;
    cin >> b;

    int sum = a*1 + b*2;
    if(!(a % 2 == 1) && !(a < 2) && !(b%2 == 0)) {
        cout << "Yes" << endl;
        return;
    } else if(!(b % 2 == 1) && !(a % 2==1)) {
        cout << "Yes" << endl;
        return;
    } else {
        cout << "No" << endl;
    }
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