#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currPath;
        return countPathsRecursive(root, targetSum, currPath);
    }

private:
    int countPathsRecursive(TreeNode* curr, int Sum, vector<int>& currPath) {
        if(curr == nullptr)
            return 0;
        
        currPath.push_back(curr->val);

        int pathCnt = 0;
        long pathSum = 0;

        for(int i = currPath.size() - 1; i >= 0; i--) {
            pathSum += currPath[i];

            if(pathSum == Sum) {
                pathCnt++;
            }
        }

        pathCnt += countPathsRecursive(curr->left, Sum, currPath);
        pathCnt += countPathsRecursive(curr->right, Sum, currPath);

        currPath.pop_back();
        return pathCnt;
    }
};