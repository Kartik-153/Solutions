/**
*  जय सिया राम
*/

#include <bits/stdc++.h>
using namespace std;

#define int           long long
#define endl          "\n"
#define rep(i, a, n)  for (int i = a; i < n; i++)

void solve(int n, vector<int>& h) {
    

    int count = 0;
    int current_pos = n - 1;

    while (current_pos > 0) {
        bool can_see = true;
        for (int i = 0; i < current_pos; i++) {
            if (h[current_pos] <= h[i]) {
                can_see = false;
                break;
            }
        }
        if (can_see) break;

        swap(h[current_pos], h[current_pos - 1]);
        current_pos--;
        count++;
    }

    cout << count << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        rep(i, 0, n) cin >> h[i];
        solve(n, h);
    }

    return 0;
}
