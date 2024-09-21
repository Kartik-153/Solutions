#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        else {
            int l_length = maxDepth(root->left);
            int r_length = maxDepth(root->right);
            if(l_length > r_length) {
                return (l_length + 1);
            }
            else {
                return (r_length + 1);
            }
        }
    }

    int MaxDepth(TreeNode* root) {
        if(root == nullptr) 
            return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int maxDepth = 0;
        while(!Q.empty()) {
            maxDepth++;
            int len = Q.size();

            for(int i = 0; i < len; i++) {
                TreeNode* currNode = Q.front();
                Q.pop();

                if(currNode->left != nullptr)
                    Q.push(currNode->left);
                if(currNode->right != nullptr) 
                    Q.push(currNode->right);
            }
        }
        return maxDepth;
    }
};