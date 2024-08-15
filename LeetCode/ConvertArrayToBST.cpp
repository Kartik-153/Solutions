#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* toTree(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = (l + r) / 2;

        TreeNode* res = new TreeNode(nums[mid]);

        res->left = toTree(nums, l, mid - 1);
        res->right = toTree(nums, mid + 1, r);

        return res;
    }
};
