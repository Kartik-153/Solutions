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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currSum) {
        if(!node) {
            return 0;
        }

        currSum = currSum * 10 + node->val;

        if(!node->left && !node->right) {
            return currSum;
        }

        return dfs(node->left, currSum) + dfs(node->right, currSum);
    }
};
