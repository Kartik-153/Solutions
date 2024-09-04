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
 

void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int winCount = 0;
    
    // Iterate over all possible combinations of 4 cards
    for (int a = 1; a <= 10; ++a) {
        for (int b = 1; b <= 10; ++b) {
            for (int c = 1; c <= 10; ++c) {
                for (int d = 1; d <= 10; ++d) {
                    
                    // Check if Suneet wins the first round
                    if (a > c) {
                        // Check if Suneet wins the second round
                        if (b > d) {
                            winCount += 1;
                        }
                        // Check if the second round is a tie
                        else if (b == d) {
                            winCount += 1;
                        }
                    }
                    // Check if the first round is a tie
                    else if (a == c) {
                        // Check if Suneet wins the second round
                        if (b > d) {
                            winCount += 1;
                        }
                    }
                }
            }
        }
    }
    
    cout << winCount << endl;
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