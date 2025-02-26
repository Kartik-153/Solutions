#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if there's a valid pair
bool findPair(TreeNode* root, unordered_map<int, vector<int>>& level_map, int target, int depth, int d) {
    if (!root) return false;

    int complement = target - root->val;

    // Check if complement exists at a different level and at distance d
    if (level_map.count(complement)) {
        for (int prev_depth : level_map[complement]) {
            if (abs(prev_depth - depth) == d) {
                return true;
            }
        }
    }

    // Store the current node's value with its depth
    level_map[root->val].push_back(depth);

    // Recur for left and right subtrees
    bool left = findPair(root->left, level_map, target, depth + 1, d);
    bool right = findPair(root->right, level_map, target, depth + 1, d);

    return left || right;
}

// Main function to check if there exists a valid pair
bool hasPairWithTarget(TreeNode* root, int target, int d) {
    unordered_map<int, vector<int>> level_map;
    return findPair(root, level_map, target, 0, d);
}

// Sample Usage
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    int target = 11;
    int d = 2;

    cout << (hasPairWithTarget(root, target, d) ? "True" : "False") << endl;

    return 0;
}
