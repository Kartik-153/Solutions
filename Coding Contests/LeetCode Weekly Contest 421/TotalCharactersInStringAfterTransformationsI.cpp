#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> letter_cnt(26, 0);

        for(char ch : s) {
            letter_cnt[ch - 'a']++;
        }

        for(int i = 0; i < t; i++) {
            vector<long long> updated_cnt(26,0);
            for(int j = 0; j < 26; j++) {
                if(j == 25) {
                    updated_cnt[0] = (updated_cnt[0] + letter_cnt[j]) % mod;
                    updated_cnt[1] = (updated_cnt[1] + letter_cnt[j]) % mod;
                } else {
                    updated_cnt[j+1] = (updated_cnt[j+1] + letter_cnt[j])%mod;
                }
            }
            letter_cnt = updated_cnt;
        }
        long long final_len = 0;
        for(int c : letter_cnt) {
            final_len = (final_len + c) % mod;
        }
        return final_len;
    }
};