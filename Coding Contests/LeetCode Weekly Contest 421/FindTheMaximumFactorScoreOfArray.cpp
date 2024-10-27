#include <bits/stdc++.h>
#include<numeric>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &nums) {
        int n = nums.size();
        long gcdAll = nums[0];
        long lcmAll = nums[0];

        for(int i = 1; i < n; i++) {
            gcdAll = gcd(gcdAll, nums[i]);
            lcmAll = lcm(lcmAll, nums[i]);
        }

        long maxScore = gcdAll*lcmAll;

        for(int i = 0; i < n; i++) {
            long currGCD = -1;
            long currentLCM = 1;

            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                 if (currGCD == -1) { 
                    currGCD = nums[j]; 
                } else { 
                    currGCD = gcd(currGCD, nums[j]); 
                } 
                 
                currentLCM = lcm(currentLCM, nums[j]); 
            } 
             
            long currentScore = currGCD * currentLCM; 
            maxScore = max(maxScore, currentScore); 
            }
            return maxScore;
        }
private:
    long gcd(long a, long b) {
        return __gcd(a,b);
    }

    long lcm(long a, long b) {
        return (a / gcd(a,b)) * b;
    }
};