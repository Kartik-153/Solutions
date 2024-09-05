#include<bits/stdc++.h>
using namespace std;

vector<int> cyclicSort(vector<int>& nums) {
    int i = 0;

    while(i < nums.size()) {
        int j = nums[i] - 1;
        if(nums[i] != nums[j]) {
            swap(nums[i], nums[j]);
        } else {
            i++;
        }
    }
    return nums;
}

int main() {

    vector<int> v = {1,3,2,5,4};
    v = cyclicSort(v);

    for(auto x: v) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}