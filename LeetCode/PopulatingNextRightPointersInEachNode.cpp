#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) 
            return root;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int len = Q.size();
            Node* prev = nullptr;

            for(int i = 0; i < len; i++) {
                Node* curr = Q.front();
                Q.pop();

                if(prev != nullptr) {
                    prev->next = curr;
                }

                prev = curr;

                if(curr->left != nullptr) {
                    Q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    Q.push(curr->right);
                }
            }
        }
        return root;
    }
};