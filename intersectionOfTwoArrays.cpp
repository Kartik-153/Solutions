#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicatesUsingStdUnique(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        return arr;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> v;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                v.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return removeDuplicatesUsingStdUnique(v);
    }
};