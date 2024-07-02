#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_n = s.size();
        int word_cnt = words.size();
        int word_len = words[0].size();
        int sub_s_len = word_cnt * word_len;
        unordered_map<string, int> dict;
        for (const auto& word : words)
            dict[word]++;
        vector<int> ans;
        int left{};
        while (left <= s_n - sub_s_len) {
            unordered_map<string, int> tmp_dict(dict);
            int i{};
            for (; i < word_cnt; i++) {
                if (auto it =
                        tmp_dict.find(s.substr(left + i * word_len, word_len));
                    it == tmp_dict.end() || --(it->second) < 0)
                    break;
            }
            if (i == word_cnt)
                ans.push_back(left);
            left += 1;
        }
        return ans;
    }
};
