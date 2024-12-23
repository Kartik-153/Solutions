#include <bits/stdc++.h>
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues[i] = node->val;

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }

private:
    int getMinSwaps(vector<int>& nums) {
        int swaps = 0;
        vector<int> target = nums;
        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }

        for (int i = 0; i < target.size(); i++) {
            if (target[i] != nums[i]) {
                swaps++;

                int currPos = pos[target[i]];
                pos[nums[i]] = currPos;
                swap(nums[currPos], nums[i]);
            }
        }
        return swaps;
    }
};