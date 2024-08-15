#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - prices[i-1];
            if(profit > 0) {
                max_profit += profit;
            }
        }
        return max_profit;
    }
};