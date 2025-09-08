#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    vector<ll> cost;
    ll c = 3;
    ll cnt = 1;
    for(int i = 0; i < 21; i++) {
        cost.push_back(c);
        c = 3*c + cnt;
        cnt *= 3; 
    }
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> tr;
        ll min_k = 0;
        
    }
    
}