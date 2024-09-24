#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        deque<vector<int>> permutations;
        permutations.push_back({});

        int numsLength = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int n = permutations.size();

            for(int p = 0; p < n; p++) {
                vector<int> oldPermutation = permutations.front();
                permutations.pop_front();

                for(int j = 0; j <= oldPermutation.size(); j++) {
                    vector<int> newPermutation = oldPermutation;

                    newPermutation.insert(newPermutation.begin() + j, currentNumber);

                    if(newPermutation.size() == numsLength) {
                        result.push_back(newPermutation);
                    } else {
                        permutations.push_back(newPermutation);
                    }
                }
            }
        }
        return result;
    }
};