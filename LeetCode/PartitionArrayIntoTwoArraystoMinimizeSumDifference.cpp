#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) { // Tabulation will fail
        int n = nums.size();
        int sum = 0;
        for(int i : nums) sum += i;
        int requiredSum = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(requiredSum+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        for(int s = 1; s <= requiredSum; s++) dp[0][s] = (nums[0] == s);
        for(int i = 1; i < n; i++) {
            for(int s = 1; s <= requiredSum; s++) {
                if(dp[i-1][s])
                    dp[i][s] = dp[i-1][s];
                else if(s >= nums[i]) 
                    dp[i][s] = dp[i-1][s-nums[i]];
            }
        }
        int s1 = 0;
        for(int i = requiredSum; i >= 0; i--) {
            if(dp[n-1][i]) {
                s1 = i;
                break;
            }
        }
        int s2 = sum - s1;
        return abs(s2-s1);
    }

class Solution2 {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int N = n/2;
        vector<vector<int>> left(N+1), right(N+1);
        
		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0; sz<=N; ++sz){
            sort(right[sz].begin(), right[sz].end());
        }

        res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));

		//iterating over left part
        for(int sz=1; sz<N; ++sz){
            for(auto &a : left[sz]){
                int b = (sum - 2*a)/2, rsz = N-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part
                
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
                if(itr!= v.begin()){
                    auto it = itr; --it;
                    res = min(res, abs(sum-2*(a+(*it))));
                }                
            }
        }
        return res;
        
    }
};
};