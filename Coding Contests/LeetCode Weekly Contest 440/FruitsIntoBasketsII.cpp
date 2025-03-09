#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int res = 0;
        vector<bool> ch(baskets.size(), false);
        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                int tmp = 0;
                if (fruits[i] <= baskets[j] && ch[j] == false) {
                    ch[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i] == false)
                res++;
        }
        return res;
    }
};