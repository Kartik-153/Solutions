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
    bool hasSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(root->val == sum && root->left == nullptr && root->right == nullptr) 
            return true;
        
        return hasSum(root->left, sum - root->val) || 
                hasSum(root->right, sum - root->val);
    }
};