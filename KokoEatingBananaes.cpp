#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        while(left<=right) {
            long long mid = (left + right) / 2;
            if(canEatInTime(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(vector<int>& piles, int k, int h) {
        long long hours = 0;
        for(int i: piles) {
            int div = i / k;
            hours += div;
            if(i%k!=0) hours++;
        }
        return hours <= h;
    }
};
