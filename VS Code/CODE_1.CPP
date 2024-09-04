#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define sortRev(a) sort(a.rbegin(),a.rend());

bool checkPalin(vector<int> &a) {
    int n = a.size();
    rep(i,0,n)
    {
        if(a[i] =! a[n-1-i]) return false;
    }
    return true;
}

bool checkSort(vector<int> &a) {
    int n = a.size();
    rep(i,0,n-1) {
        if(a[i]>a[i+1]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n),v1,v2;
        rep(i,0,n) cin >> a[i];
        bool f1 = 0,f2 = 0;
        for(int i = 0; i < n/2; i++) {
            if(a[i]>a[n-i-1]) {
                f1 = 1;
                break;
            }
        }
        if(f1 == 1) cout << "-1";
        else {
            for(int i = 0; i < n/2; i++) {
                v1.pb(a[n-i-1] - a[i]);
                v2.pb(a[n-i-1] - a[i]);
            }
            sortRev(v2);
            for(int i = 0; i < n/2; i++) {
                if(v1[i] != v2[i]) {
                    f2 = 1;
                    break;
                }
            }
            if(f2 == 1) cout << "-1";
            else cout << v1[0];
        }
        cout << endl;
    }
    return 0;
}

// "C:\msys64\ucrt64\bin\gcc.exe"