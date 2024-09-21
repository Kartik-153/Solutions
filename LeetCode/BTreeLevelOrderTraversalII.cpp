#include<bits/stdc++.h>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> DQ;
        if (root == nullptr)
            return res;
        DQ.push_back(root);
        while (!DQ.empty()) {
            int length = DQ.size();
            vector<int> temp;
            for (int i = 0; i < length; i++) {
                TreeNode* currNode = DQ.front();
                if (currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if (currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
                temp.push_back(currNode->val);
                DQ.pop_front();
            }
            res.insert(res.begin(), temp);
        }
        return res;
    }
};
