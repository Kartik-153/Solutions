#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size() + 1;

    int x1 = 1;
    for(int i = 2; i <= n; i++) {
        x1 = x1 ^ i;
    }

    int x2 = nums[0];
    for(int i = 1; i < n-1; i++) {
        x2 = x2 ^ nums[i];
    }

    return x1^x2;
}

int main() {

    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,14};
    cout << missingNumber(nums);

    return 0; 
}

/*
Taking XOR of a number with itself returns 0, e.g.,
    1 ^ 1 = 0
    29 ^ 29 = 0
Taking XOR of a number with 0 returns the same number, e.g.,
    1 ^ 0 = 1
    31 ^ 0 = 31
XOR is Associative & Commutative, which means:
    (a ^ b) ^ c = a ^ (b ^ c)
    a ^ b = b ^ a
*/