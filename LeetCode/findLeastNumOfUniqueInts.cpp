#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        for(auto i : arr) {
            frequency[i]++;
        }
        vector<pair<int,int>>dp;
        for(auto i: frequency)
            dp.push_back(i);
        sort(begin(dp), end(dp), [](auto a, auto b) {
            return a.second < b.second;
        });
        int count = 0;
        for(auto i: dp) {
            if(k >= i.second) {
                k -= i.second;
                count++;
            }
            else {
                break;
            }
        }
        return dp.size() - count;
    }
};

class Solution2 {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        for (int number : arr) {
            freqMap[number]++;
        }
        vector<int> freq;
        for(const auto& pair: freqMap) {
            freq.push_back(pair.second);
        }
        sort(freq.begin(), freq.end());
        int res = freq.size();
        for(int n: freq) {
            if(k>=n) {
                k-=n;
                res--;
            } else {
                return res;
            }
        }
        return res;
    }
};
