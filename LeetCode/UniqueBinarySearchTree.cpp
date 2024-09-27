#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) {
            return 1;
        }

        int count = 0;
        for(int i = 1; i <= n; i++) {
            int countOfLeftSubtrees = numTrees(i - 1);
            int countOfRightSubtrees = numTrees(n - i);
            count+=(countOfLeftSubtrees*countOfRightSubtrees);
        }
        return count;
    }
};

class Solution { // memomised version
public:
    int numTrees(int n) {
        unordered_map<int, int> memo;
        return countTreesRec(memo, n);
    }
private:
    int countTreesRec(unordered_map<int, int>& memo, int n) {
        if(memo.find(n) != memo.end()) {
            return memo[n];
        }

        if(n <= 1) {
            return 1;
        }

        int count = 0;

        for(int i = 1; i <= n; i++) {
            int countOfLeftSubTrees = countTreesRec(memo, i - 1);
            int countOfRightSubTrees = countTreesRec(memo, n - i);
            count+=(countOfLeftSubTrees*countOfRightSubTrees);
        }

        memo[n] = count;
        return count;
    }
};