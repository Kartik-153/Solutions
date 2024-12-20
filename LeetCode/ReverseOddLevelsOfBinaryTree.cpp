#include <bits/stdc++.h>
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<TreeNode*> currlevelNodes;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                currlevelNodes.push_back(node);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(level % 2 != 0) {
                int l = 0, r = currlevelNodes.size() - 1;
                while(l < r) {
                    int temp = currlevelNodes[l]->val;
                    swap(currlevelNodes[l]->val, currlevelNodes[r]->val);
                    l++;
                    r--;
                }
            }

            level++;
        }
        return root;
    }
};