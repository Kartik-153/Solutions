#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    cout << n << " ";
    while (n != 1 && n != 0) {
        if (n % 2 == 0 && n != 0) {
            n /= 2;
            cout << n << " ";
        }
        else if (n % 2 != 0) {
            n = 3 * n + 1;
            cout << n << " ";
        }
    }
    return 0;
}