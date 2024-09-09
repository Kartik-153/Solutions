#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
// Method 1 (Cyclic Sort)
    int findDuplicate(vector<int>& nums) {
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] != i + 1) {
                int j = nums[i] - 1;
                if (nums[i] != nums[j]) {
                    swap(nums[i], nums[j]);
                } else {
                    return nums[i];
                }
            } else {
                i++;
            }
        }
        return -1;
    }

// Method 2 - (Two Pointers) - fast and slow pointers
    int findDuplicate2(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int current = nums[nums[slow]];
        int cycleLength = 1;
        while(current != nums[slow]) {
            current = nums[current];
            cycleLength++;
        }
        return findStart(nums, cycleLength);
    }

private:
    int findStart(vector<int>& nums, int cycleLength) {
        int pointer1 = nums[0];
        int pointer2 = nums[0];
        
        while(cycleLength > 0) {
            pointer2 = nums[pointer2];
            cycleLength--;
        }

        while(pointer1 != pointer2) {
            pointer1 = nums[pointer1];
            pointer2 = nums[pointer2];
        }

        return pointer1;
    }
};
