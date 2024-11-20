/**
*  जय सिया राम
*/

#include <bits/stdc++.h>
using namespace std;

#define int           long long int
#define endl          "\n"
#define rep(i,a,n)    for(int i = a; i < n; i++)
#define all(p)        p.begin(), p.end()
#define pb            push_back
#define F             first
#define S             second
#define mod           1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];
    int maxValue = 0, maxIndex = -1;
    rep(i, 0, n) {
        int curr = max(A[i], B[i]);
        if (curr > maxValue) {
            maxValue = curr;
            maxIndex = i;
        }
    }
    int lar = 0, larIndex = -1, lar2 = 0, larIndex2 = -1;

    for (int i = n - 1; i >= 0; --i) {
        if (A[i] > lar) {
            lar2 = lar;
            larIndex2 = larIndex;
            lar = A[i];
            larIndex = i;
        } else if (A[i] > lar2) {
            lar2 = A[i];
            larIndex2 = i;
        }
    }
    lar = max(A[larIndex], B[larIndex]);
    lar2 = max(A[larIndex2], B[larIndex2]);
    if (lar == lar2 && maxValue == lar)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
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