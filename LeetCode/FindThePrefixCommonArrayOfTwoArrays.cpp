#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixArray(n);

        for (int i = 0; i < n; i++) {
            int commCnt = 0;

            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= i; k++) {
                    if (A[j] == B[k]) {
                        commCnt++;
                        break;
                    }
                }
            }
            prefixArray[i] = commCnt;
        }

        return prefixArray;
    }
};

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);

        unordered_set<int> eleA, eleB;

        for (int i = 0; i < n; i++) {
            eleA.insert(A[i]);
            eleB.insert(B[i]);

            int commCnt = 0;

            for (int element : eleA) {
                if (eleB.count(element)) {
                    commCnt++;
                }
            }
            res[i] = commCnt;
        }
        return res;
    }
};
