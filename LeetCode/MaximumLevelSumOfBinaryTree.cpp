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
    int maxLevelSum(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> q;
        int level = 0;
        q.push_back(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel;
            int currSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop_front();
                currSum += currNode->val;
                if (currNode->left != nullptr) {
                    q.push_back(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push_back(currNode->right);
                }
            }
            res.push_back(currSum);
        }
        int n = res.size();
        return distance(res.begin(), max_element(res.begin(), res.end())) + 1;
    }
};

