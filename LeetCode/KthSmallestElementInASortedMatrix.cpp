#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n-1][n-1];

        while(start<end) {
            int mid = start + (end - start) / 2;
            int smaller = matrix[0][0];
            int larger = matrix[n-1][n-1];

            int count = countLessEqual(matrix, mid, smaller, larger);

            if(count == k) {
                return smaller;
            } 
            if(count < k) {
                start = larger;
            } else {
                end = smaller;
            }
        }
        return start;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int& smaller, int& larger) {
        int count = 0;
        int n = matrix.size();
        int row = n-1, col=0;
         
        while(row >= 0 && col < n) {
            if(matrix[row][col] > mid) {
                larger = min(larger, matrix[row][col]);
                row--;
            } else {
                smaller = max(smaller, matrix[row][col]);
                count+=row + 1;
                col++;
            }
        }
        return count;
    }
};
