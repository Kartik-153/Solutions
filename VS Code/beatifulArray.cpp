#include<bits/stdc++.h>
using namespace std;


int beautiful_array(vector<int>& nums, int n) {
    sort(nums.begin(), nums.end());
    int minele = nums[0];
    int maxele = nums[n-1];
    return (maxele - minele);
}

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        vector<int> arr;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << beautiful_array(arr, n) << endl;
    }
    return 0;
}