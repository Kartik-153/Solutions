#include<bits/stdc++.h>
using namespace std;

int kthLargestElement(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minheap;

    for(int i = 0; i < k; ++i) 
        minheap.push(nums[i]);
    
    for(int i = k; i < nums.size(); ++i) {   
        if(nums[i] > minheap.top()) {
            minheap.pop();
            minheap.push(nums[i]);
        }
    }
    return minheap.top();
}

int main() {
    vector<int> num = {9,0,8,10,-1};
    cout << kthLargestElement(num, 2);
    return 0;
}