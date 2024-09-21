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

class Solution2 { // Memory Limit Exceed
public:
    template <class Key, class Value>
        pair<Key, Value> findMaxValuePair(
        unordered_map<Key, Value> const &x) {
        return *std::max_element(x.begin(), x.end(),
                             [](const std::pair<Key, Value> &p1,
                                const std::pair<Key, Value> &p2)
                             {
                                 return p1.second < p2.second;
                             });
    }

    int maxLevelSum(TreeNode* root) {
        deque<TreeNode*> DQ;
        int res = 0;
        DQ.push_back(root);
        int l = 1;
        unordered_map<int, int> mm;
        while(!DQ.empty()) {
            int len = DQ.size();
            int tempSum = 0;
            for(int i = 0; i < len; i++) {
                TreeNode* currNode = DQ.front();
                DQ.pop_back();
                tempSum += currNode->val;
                if(currNode->left != nullptr) {
                    DQ.push_back(currNode->left);
                }
                if(currNode->right != nullptr) {
                    DQ.push_back(currNode->right);
                }
            }
            mm[l] = tempSum;
            l+=1;
        }
        // int maxElement = max_element(mm.begin(), mm.end(),{return x.second < y.second;});
        pair<int, int> x = findMaxValuePair(mm);
        return x.first;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> Q; // Use queue instead of deque
        Q.push(root);

        int maxSum = root->val;
        int maxLevel = 1;
        int currentLevel = 1;

        // Perform level-order traversal
        while (!Q.empty()) {
            int levelSize = Q.size();
            int tempSum = 0;

            // Sum all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = Q.front();
                Q.pop();

                tempSum += currentNode->val;

                // Add children to the queue
                if (currentNode->left != nullptr) {
                    Q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    Q.push(currentNode->right);
                }
            }

            // Check if the current level's sum is the largest
            if (tempSum > maxSum) {
                maxSum = tempSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};