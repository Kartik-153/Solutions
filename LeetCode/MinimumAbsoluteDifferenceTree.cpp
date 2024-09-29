#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> v;
        toVector(root, v);
        sort(v.begin(), v.end());

        int min_diff = INT_MAX;
        for (size_t i = 1; i < v.size(); ++i)
        {
            min_diff = min(min_diff, v[i] - v[i - 1]);
        }
        return min_diff;
    }

private:
    void toVector(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            toVector(root->left, v);
            v.push_back(root->val);
            toVector(root->right, v);
        }
    }
};
