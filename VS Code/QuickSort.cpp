#include<bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int>& nums) { // Quick Sort implementation

    if(nums.size() == 1) return nums;

    int pivot = nums[nums.size() - 1];
    vector<int> firstHalf;
    vector<int> secondHalf;

    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] < pivot) {
            firstHalf.push_back(nums[i]);
        } else {
            secondHalf.push_back(nums[i]);
        }
    }

    if(!firstHalf.empty() && !secondHalf.empty()) {
        vector<int> sortedFirstHalf = quickSort(firstHalf);
        vector<int> sortedSecondHalf = quickSort(secondHalf);
        sortedFirstHalf.push_back(pivot);
        sortedFirstHalf.insert(sortedFirstHalf.end(), sortedSecondHalf.begin(), sortedSecondHalf.end());
        return sortedFirstHalf;
    } else if(!firstHalf.empty()) {
        vector<int> sortedFirstHalf = quickSort(firstHalf);
        sortedFirstHalf.push_back(pivot);
        return sortedFirstHalf;
    } else {
        vector<int> sortedSecondHalf = quickSort(secondHalf);
        sortedSecondHalf.insert(sortedSecondHalf.begin(), pivot);
        return sortedSecondHalf;
    }
}

// Function to find the K largest numbers
vector<int> findKLargestNumbers(vector<int>& nums, int k) {
    vector<int> sortedArray = quickSort(nums);
    return vector<int>(sortedArray.end() - k, sortedArray.end());
}

// Helper function to print the array
void printTopK(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> x1 = {3, 1, 5, 12, 2, 11};
    vector<int> result1 = findKLargestNumbers(x1, 2);
    cout << "Here are the top K numbers: ";
    printTopK(result1);

    // vector<int> result2 = findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
    // cout << "Here are the top K numbers: ";
    // printTopK(result2);

    return 0;
}
