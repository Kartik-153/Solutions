#include <bits/stdc++.h>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        int inorderIndex = 0;

        for(int i = 1; i < preorder.size(); i++) {
            TreeNode* currentNode = nodeStack.top();
            if(currentNode->val != inorder[inorderIndex]) {
                currentNode->left = new TreeNode(preorder[i]);
                nodeStack.push(currentNode->left);
            } else {
                while(!nodeStack.empty() && nodeStack.top()->val == inorder[inorderIndex]) {
                    currentNode = nodeStack.top();
                    nodeStack.pop();
                    inorderIndex++;
                }
                if(inorderIndex < inorder.size()) {
                    currentNode->right = new TreeNode(preorder[i]);
                    nodeStack.push(currentNode->right);
                }
            }
        }
        return root;
    }
};