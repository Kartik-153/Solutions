#include <bits/stdc++.h>
using namespace std;



    void removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> c = nums;
        // nums.clear();
        for(auto& it: s) {
            cout << it << endl;
        }
        nums = {};
        for(auto& it: s) {
            nums.push_back(it);
        }
        for(int i: nums) {
            cout << i << endl;
        }
        // return c.size() - s.size();
    }

int main() {
    vector<int> s = {1,1,2};
    removeDuplicates(s);
}
