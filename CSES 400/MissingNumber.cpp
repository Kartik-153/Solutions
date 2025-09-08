#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n-1);
    for(ll i = 0; i < n - 1; i++) cin >> v[i];
    ll sum = ((n)*(n+1))/2;
    ll _sum_ = 0;
    for(auto x: v) {
        _sum_ += x;
    }
    cout << sum - _sum_;
    return 0;
}