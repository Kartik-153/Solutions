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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        deque<TreeNode*> DQ;
        if(root == nullptr)
            return res;
        DQ.push_back(root);

        while(!DQ.empty()) {
            int len = DQ.size();
            double currSum = 0;

            for(int i = 0; i < len; i++) {
                TreeNode* currNode = DQ.front();
                DQ.pop_front();
                currSum += double(currNode->val);
                if(currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if(currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
            }
            res.push_back(currSum / len);
        }
        return res;
    }
};