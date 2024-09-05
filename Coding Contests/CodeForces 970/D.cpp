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
 

const int N = 200010;
int n, a[N], ans[N], cnt;
bool vis[N];
string s;

int dfs(int p){
    if (vis[p - 1]){
        return cnt;
    }
    vis[p - 1] = 1;
    if(s[p - 1] == '0') cnt++;
    ans[p - 1] = dfs(a[p - 1]);
    return cnt;
}

void solve() {
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s = "";
    cin >> s;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        if (ans[i - 1] == -1) {
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            ans[i - 1] = dfs(i);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
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