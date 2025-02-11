#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(auto price: prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(price - minPrice, maxProfit);
        }
        return maxProfit;
    }
};