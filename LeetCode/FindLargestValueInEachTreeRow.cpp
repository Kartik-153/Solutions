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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) 
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();
            int currMax = INT_MIN;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                currMax = max(currMax, currNode->val);

                if(currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }
            res.push_back(currMax);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> ans;
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
private:
    void dfs(TreeNode* root, int depth) {
        if(root == nullptr)
            return;
        
        if(depth == ans.size()) 
            ans.push_back(root->val);
        else 
            ans[depth] = max(ans[depth], root->val);
        
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        vector<int> ans;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 0));
        
        while (!stack.empty()) {
            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            TreeNode* node = pair.first;
            int depth = pair.second;
            
            if (depth == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[depth] = max(ans[depth], node->val);
            }
            
            if (node->left) {
                stack.push(make_pair(node->left, depth + 1));
            }
            
            if (node->right) {
                stack.push(make_pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
};