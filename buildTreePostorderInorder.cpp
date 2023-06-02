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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postIndex];
        TreeNode* root = new TreeNode(rootVal);
        postIndex--;
        int rootIndex = -1;
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postIndex);
        root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postIndex);

        return root;
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};