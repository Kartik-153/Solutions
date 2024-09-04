/**
 *  जय सिया राम
 */

#include <bits/stdc++.h>

#define pb push_back
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define yes cout << "YES"
#define no cout << "NO"
#define nl "\n"
#define loop(i, n) for (int i = 0; i < (int)n; i++)
#define loop1(i, n) for (int i = 1; i <= (int)n; i++)
#define loopab(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define all(a) (a).begin(), (a).end()
ll MOD = 1e9 + 7;
ll pw(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = pw(a, b / 2);
    if (b % 2 == 0)
        return 1ll * t * t % MOD;
    else
        return 1ll * t * t * a % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    loop(i, n) cin >> a[i];
    ll lo = 0; 
    ll le = 0; 
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1 && a[i] > lo)
            lo = a[i];
        if (a[i] % 2 == 0 && a[i] > le)
            le = a[i];
    }

    int c = 0;
    bool all_same_parity = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % 2 != a[0] % 2)
        {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity)
    {
        cout << 0 << nl;
        return;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < lo)
        {
            c++;
            a[i] = a[i] + lo;
            lo = max(lo, a[i]);
        }
    }

    all_same_parity = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % 2 != a[0] % 2)
        {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity)
    {
        cout << c << nl;
        return;
    }

    ll indx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1 && a[i] == lo)
        {
            indx = i;
            break;
        }
    }

    a[indx] = lo + le;
    c++;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            c++;
        }
    }
    cout << c << nl;
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}