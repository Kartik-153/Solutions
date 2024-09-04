#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintInorder(struct TreeNode* node) { // In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order.
    if(node == nullptr) 
        return;
    PrintInorder(node->left);
    cout << node->val << " ";
    PrintInorder(node->right);
}

void PrintPreorder(struct TreeNode* node) { // Preorder traversal is used to create a copy of the tree.
                                                // Preorder traversal is also used to get prefix expressions on an expression tree.
    if(node == nullptr)
        return;
    cout << node->val << " ";
    PrintPreorder(node->left);
    PrintPreorder(node->right);
}

void PrintPostorder(TreeNode* node) { // Postorder traversal is used to delete the tree
    if(node == nullptr)               // Postorder traversal is also useful to get the postfix expression of an expression tree.
        return;                       // Postorder traversal can help in garbage collection algorithms, particularly in systems where manual memory management is used.
                                      
    PrintPostorder(node->left);
    PrintPostorder(node->right);
    cout << node->val << " ";
}

void PrintLevelorder(TreeNode* root) {
    if(root==nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while(q.empty() == false) {
        TreeNode* node = q.front();
        cout << node->val << " ";
        q.pop();

        if(node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right); 
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    cout << "Inorder traversal of the binary tree is: ";
    PrintInorder(root);
    cout << endl;
    cout << "Postorder traversal of the binary tree is: ";
    PrintPostorder(root);
    cout << endl;
    cout << "Preorder traversal of the binary tree is: ";
    PrintPreorder(root);
    cout << endl;
    cout << "Level Order traversal of the binary tree is: ";
    PrintLevelorder(root);
    cout << endl;

    // return 0;
    // std::cout << "Minimum value for long: " << std::numeric_limits<long>::min() << std::endl;
    // std::cout << "Maximum value for long: " << std::numeric_limits<long>::max() << std::endl;
    return 0;
}
