#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root, int key) {
        if(root == nullptr) 
            return root;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {
            TreeNode* currNode = Q.front();
            Q.pop();

            if(currNode->left != nullptr) {
                Q.push(currNode->left);
            }
            if(currNode->right != nullptr) {
                Q.push(currNode->right);
            }

            if(currNode->val == key) return Q.front();
        }
        if(Q.size() > 0) return Q.front();

        return nullptr;
    }
};