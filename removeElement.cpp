#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); it++) {
            if(*it != val) {
                result ++;
            }
        } 

        for(auto i = nums.begin(); i != nums.end(); ++i) {
            if(*i == val) {
                nums.erase(i);
                i--;
            }
        }
        return result;
    }
};