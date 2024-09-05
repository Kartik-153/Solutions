#include <bits/stdc++.h>

using namespace std;

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

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
