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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> DQ;
        DQ.push_back(root);
        if(root == nullptr)
            return res;
        bool leftToRight = true;

        while(!DQ.empty()) {
            int Qlen = DQ.size();
            vector<int> currLevel;

            for(int i = 0; i < Qlen; i++) {
                TreeNode* currNode = DQ.front();
                DQ.pop_front();

                if(leftToRight) {
                    currLevel.push_back(currNode->val);
                } else {
                    currLevel.insert(currLevel.begin(), currNode->val);
                }

                if(currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if(currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
            }
            res.push_back(currLevel);
            leftToRight = !leftToRight;
        }
        return res;
    }
};