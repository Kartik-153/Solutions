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
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
private:
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }

        if(memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }

        for(int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubTree = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTree = allPossibleBST(i + 1, end, memo);
            
            for(auto left : leftSubTree) {
                for(auto right : rightSubTree) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = res;
    }
};