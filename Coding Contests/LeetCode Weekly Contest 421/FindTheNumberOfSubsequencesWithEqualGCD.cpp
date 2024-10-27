#include<bits/stdc++.h>
using namespace std;

class Solution { // Wrong Answer
public:
const int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxNum + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        vector<long long> gcdCount(maxNum + 1, 0);
        for (int g = maxNum; g >= 1; g--) {
            long long subseqCount = 0;
            for (int multiple = g; multiple <= maxNum; multiple += g) {
                subseqCount += freq[multiple];
            }
            if (subseqCount > 0) {
                long long totalSubsequences = (modularExponentiation(2, subseqCount, MOD) - 1 + MOD) % MOD;
                for (int multiple = 2 * g; multiple <= maxNum; multiple += g) {
                    totalSubsequences = (totalSubsequences - gcdCount[multiple] + MOD) % MOD;
                }
                
                gcdCount[g] = totalSubsequences;
            }
        }
        long long result = 0;
        for (int g = 1; g <= maxNum; g++) {
            if (gcdCount[g] > 0) {
                result = (result + gcdCount[g] * (gcdCount[g] - 1) / 2) % MOD;
            }
        }
        
        return result;

    }

    private:
    long long modularExponentiation(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
