#include <bits/stdc++.h>
using namespace std;

struct P{
    int id;
    int runs;
    int wickets;
};

bool comparePlayersScore(const P &a, const P &b) {
    return (a.runs + a.wickets * 20) > (b.runs + b.wickets * 20);
}

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        vector<P> Players;
        for(int i = 0; i < 22; i++) {
            P x;
            x.id = i + 1;
            cin >> x.runs;
            cin >> x.wickets;
            Players.push_back(x);
        }
        sort(Players.begin(), Players.end(), comparePlayersScore);
        cout << Players[0].id << endl;
    }
    return 0;
}