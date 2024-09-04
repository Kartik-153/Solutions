#include<bits/stdc++.h>
using namespace std;

int maxSumBruteForce(vector<int>& nums, int k) { // O(n*k) time Complexity
    int maxS = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n - k + 1; i++) {
        int curr_sum = 0;
        for(int j = 0; j < k; j++) {
            curr_sum = curr_sum + nums[i+j];
        }
        maxS = max(curr_sum, maxS);
    }
    return maxS;
}

int maxSumSlidingWindow(vector<int>& nums, int k) { // O(n) time complexity
    int maxSum = INT_MIN;
    for(int i = 0; i < k; i++) {
        maxSum += nums[i];
    }
    int curr_win = maxSum;
    for(int i = k; i < nums.size(); i++) {
        curr_win += nums[i] - nums[i-k];
        maxSum = max(maxSum, curr_win);
    }
    return maxSum;
}

// Smallest subarray with sum greater than a given value

int smallestSubWithSumBruteForce(vector<int>& nums, int x) {
    int n = nums.size();
    int min_len = n + 1;
    for(int start = 0; start < n; start++) {
        int curr_sum = nums[start];
        if(curr_sum > x) return 1;
        for(int end = start+1; end<n; end++) {
            curr_sum+=nums[end];
            if(curr_sum > x && (end - start + 1) < min_len)
                min_len = (end - start + 1);
        }
    }
    return min_len;
}


int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    int k = 0;
    cin >> k;
    cout << maxSumBruteForce(v, k);
    return 0;
}