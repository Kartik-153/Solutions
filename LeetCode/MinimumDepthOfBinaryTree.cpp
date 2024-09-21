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
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        deque<TreeNode*> DQ;
        DQ.push_back(root);
        int minTreeDepth = 0;
        while(!DQ.empty()) {
            minTreeDepth++;
            int levelSize = DQ.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* currNode = DQ.front();
                DQ.pop_front();
                if(currNode->left == nullptr && currNode->right == nullptr) {
                    return minTreeDepth;
                }
                if(currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if(currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
            }
        }
        return 0;
    }
};