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
        return size(dp)-count;
    }
};
