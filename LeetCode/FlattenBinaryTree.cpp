#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
    private:
    TreeNode* flattenTree(TreeNode* node) {
        if (!node) {
            return nullptr;
        }

        if (!node->left && !node->right) {
            return node;
        }

        TreeNode* leftTail = flattenTree(node->left);
        TreeNode* rightTail = flattenTree(node->right);

        if (leftTail) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        return rightTail ? rightTail : leftTail;
    }
};
