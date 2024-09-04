#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j+1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    int n = 4;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s); 
    }
    Solution sol;
    sol.decode(sol.encode(strs));
    return 0;
} 