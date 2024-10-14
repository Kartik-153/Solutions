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
    int dfs_khLargestPerfectSubtree(TreeNode* root, vector<int>& values) {
        if (!root)
            return 0;

        int right = dfs_khLargestPerfectSubtree(root->right, values);
        int left = dfs_khLargestPerfectSubtree(root->left, values);

        int count_nodes = -1;
        if (right == left) {
            count_nodes = (left + right) + 1;
            values.push_back(count_nodes);
        }

        return count_nodes;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> values;

        int val = dfs_khLargestPerfectSubtree(root, values);
        sort(values.begin(), values.end(), greater<int>());
        return k > values.size() ? -1 : values[k - 1];
    }
};
