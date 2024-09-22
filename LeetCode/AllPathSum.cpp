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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currPath;
        findAPtath(root, targetSum, currPath, allPaths);
        return allPaths;
    }

private:
    void findAPtath(TreeNode* curr, int sum, vector<int>& currPath,
                    vector<vector<int>>& allPaths) {
        if (curr == nullptr) {
            return;
        }
        currPath.push_back(curr->val);

        if (curr->val == sum && curr->left == nullptr &&
            curr->right == nullptr) {
            allPaths.push_back(currPath);
        } else {
            findAPtath(curr->left, sum - curr->val, currPath, allPaths);
            findAPtath(curr->right, sum - curr->val, currPath, allPaths);
        }

        currPath.pop_back();
    }
};