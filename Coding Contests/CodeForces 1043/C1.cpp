#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20;
ll p[N];

// 387420489

ll func(ll x) {
    return p[x+1] + x*p[x-1];
}

int main() {
    p[0] = 1;
    for(ll i = 1; i < N; i++) p[i] = p[i-1]*3;

    int t = 0;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll ans = 0;
        ll x = 0;

        while(n) {
            ans += func(x) * (n % 3);
            n /= 3;
            x++;
        }
        cout << ans << endl;
    }
    return 0;
}
