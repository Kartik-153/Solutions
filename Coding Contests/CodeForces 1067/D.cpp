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
typedef pair<int, int> pi;
typedef vector<pi> vpi;

vpi go(string S) {
    vpi ans;
    int N = S.size();

    while(true) {
        bool allZero = true;
        for(char c : S) {
            if(c == '1') allZero = false;
        }
        if(allZero) break;
        
    }
}

bool check(string str, int s, int e) {
    int n = str.size();
    if(s < 0 || e >= n) return false;
    while (s <= e) {
        if (str[s] != str[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;    
}



void solve() {
    string str, t;
    int n;
    cin >> n >> str >> t;
    
    int s = 0;
    int e = s + 1;
    while(s < e) {
        if(check(str, s, e)){
            for(int i = s; i <= e; i++) {
                pair<int, int> p;
                if(!str[i] == t[i]) {
                    
                }
            }
        }
    }
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