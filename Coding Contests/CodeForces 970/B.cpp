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
 

bool isPerfectSquare(int n) {
    int __r = sqrt(n);
    return __r * __r == n;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(!isPerfectSquare(n)) {
        cout << "No" << endl;
        return;
    }
    int r = sqrt(n);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < r; j++) {
            int index = r*i + j;
            if(i == 0 || j == 0 || i == r - 1 || j == r - 1) {
                if(s[index] != '1') {
                    cout << "No" << endl;
                    return;
                }
            } else {
                if(s[index] != '0') {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return;
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
