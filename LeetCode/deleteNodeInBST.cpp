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
    TreeNode *getS(TreeNode *curr)
    {
        curr = curr->right;
        while (curr != NULL && curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *succ = getS(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};