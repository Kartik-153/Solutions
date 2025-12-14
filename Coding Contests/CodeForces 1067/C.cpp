/**
 *  जय सिया राम
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
#define print1(a)    \
    for (auto x : a) \
        cout << x.F << " " << x.S << endl;
#define mod 1000000007
int annoyingGame(vector<int> &, vector<int> &, int, int);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i, 0, n)
    {
        cin >> b[i];
    }
    cout << annoyingGame(a, b, k, n) << endl;
    return;
}

int annoyingGame(vector<int> &a, vector<int> &b, int k, int n)
{
    vector<int> pre(n + 2, 0), suff(n + 2, 0);
    int ans = INT_MIN;
    rep(i, 0, n)
    {
        pre[i + 1] = max(0ll, a[i] + pre[i]);
        if (i < n - 1)
        {
            suff[n - i - 2] = max(0ll, a[n - i - 1] + suff[n - i - 1]);
        }
    }
    rep(i, 0, n)
    {
        if (k % 2 == 0)
        {
            ans = max(ans, max(pre[i] + a[i], suff[i] + a[i]));
        }
        else
        {
            ans = max(ans, pre[i] + suff[i] + a[i] + b[i]);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}