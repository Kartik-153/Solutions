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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        deque<TreeNode*> DQ;

        DQ.push_back(root);
        priority_queue<long long> QP;
        while (!DQ.empty()) {
            int length = DQ.size();
            long long temp = 0;
            for (int i = 0; i < length; i++) {
                TreeNode* currNode = DQ.front();
                if (currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if (currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
                temp += currNode->val;
                DQ.pop_front();
            }
            QP.push(temp);
        }
        if (QP.size() < k)
            return -1;
        for (int i = 0; i < k - 1; i++)
            QP.pop();
        return QP.top();
    }
};
