#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution { // Wrong Answer
public:
    ll minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<ll> costs;

        for (int i = 0; i <= n - x; i++) {
            vector<int> subarr(nums.begin() + i, nums.begin() + i + x);
            sort(subarr.begin(), subarr.end());
            int median = subarr[x / 2];
            costs.push_back(computeCosts(subarr, median));
        }

        ll res = 0;
        sort(costs.begin(), costs.end());
        if(costs.size() < k) return -1;
        res = accumulate(costs.begin(), costs.begin() + k, 0LL);
        return res;
    }

private:
    ll computeCosts(vector<int>& subarr, int target) {
        ll cost = 0;
        for (auto s : subarr) {
            cost += abs(s - target);
        }
        return cost;
    }
};