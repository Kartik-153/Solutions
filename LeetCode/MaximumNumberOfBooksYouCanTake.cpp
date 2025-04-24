#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        long long res = 0, currSum = books[0];
        int n = books.size();

        for(int i = 1; i < n; i++) {
            if(books[i - 1] < books[i]) {
                currSum += books[i];
            } else {
                currSum = books[i];
            }
            res = max(res, currSum);
        }
        return max(res, (long long)books[0]);
    }
};

int main() {
    Solution s;
    vector<int> books = {8,2,3,7,3,4,0,1,4,3};
    cout << s.maximumBooks(books);
    return 0;
}