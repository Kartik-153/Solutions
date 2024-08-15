#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int lheight = height(node->left);
        int rheight = height(node->right);
        return max(lheight, rheight) + 1;
    }

    void currLevel(TreeNode* root, int level, vector<int>& levelNodes) {
        if (root == nullptr)
            return;
        if (level == 1) {
            levelNodes.push_back(root->val);
        } else if (level > 1) {
            currLevel(root->left, level - 1, levelNodes);
            currLevel(root->right, level - 1, levelNodes);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int h = height(root);
        for (int i = 1; i <= h; ++i) {
            vector<int> levelNodes;
            currLevel(root, i, levelNodes);
            ans.push_back(levelNodes);
        }
        return ans;
    }
};
