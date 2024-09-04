#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        char a[8][8];
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cin >> a[i][j];
            }
        }
        string s = "";
         for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if((a[j][i] - 'a') <= 26 && (a[j][i] - 'a') >= 0) {
                    s = s + a[j][i];
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}