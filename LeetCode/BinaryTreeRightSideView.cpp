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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int len = Q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* curr = Q.front();
                if(i == len - 1) 
                    res.push_back(curr->val);
                if(curr->left != nullptr) 
                    Q.push(curr->left);
                if(curr->right != nullptr) 
                    Q.push(curr->right);
            }
        }
        return res;
    }
};