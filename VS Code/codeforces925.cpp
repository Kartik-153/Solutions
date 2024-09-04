#include<bits/stdc++.h>
using namespace std;

string find_word(int x) {
    int word_sum = 0;
    string result = "";
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                word_sum = i + j + k + 3;
                if(word_sum == x) {
                    result.push_back('a'+i);
                    result.push_back('a'+j);
                    result.push_back('a'+k);
                    return result;
                }
            }
        }
    }
    return "";
}

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        cout << find_word(a) << endl;
    }
    return 0;
}