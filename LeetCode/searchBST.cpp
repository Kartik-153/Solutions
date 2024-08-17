#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return root;
        TreeNode *node = new TreeNode();
        if (root->val == val)
        {
            node = root;
        }
        else if (root->val < val)
        {
            node = searchBST(root->right, val);
        }
        else
        {
            node = searchBST(root->left, val);
        }
        return node;
    }
};