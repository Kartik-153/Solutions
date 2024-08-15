#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        for(int i = 0; i < heights.size(); i++)
            expected.push_back(heights[i]);

        sort(expected.begin(), expected.end());

        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            if(expected[i] != heights[i])
                res+=1;
        }
        return res;
    }
};
