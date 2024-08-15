#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<int> v;
        toVector(root, v);
        return v.size();
    }

private:
    void toVector(TreeNode* root, vector<int>& v) {
        if (root) {
            toVector(root->left, v);
            v.push_back(root->val);
            toVector(root->right, v);
        }
    }
};
