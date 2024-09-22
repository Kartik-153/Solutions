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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        findAPath(root, "", allPaths);
        return allPaths;
    }

private:
    void findAPath(TreeNode* curr, string currPath, vector<string>& allPaths) {
        if(curr == nullptr) 
            return;
        
        if(!currPath.empty()) {
            currPath += "->";
        }
        currPath += to_string(curr->val);

        if(curr->left == nullptr && curr->right == nullptr) {
            allPaths.push_back(currPath);
        } else {
            findAPath(curr->left, currPath, allPaths);
            findAPath(curr->right, currPath, allPaths);
        }
    }
};