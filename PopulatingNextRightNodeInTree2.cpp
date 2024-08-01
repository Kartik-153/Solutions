#include<bits/stdc++.h>
using namespace std;


 void connect(Node* root) {
        Node* level_start = root;

        while (level_start) {
            Node* current = level_start;
            Node* prev = nullptr;
            level_start = nullptr;

            while (current) {
                if (current->left) {
                    if (prev) {
                        prev->next = current->left;
                    } else {
                        level_start = current->left;
                    }
                    prev = current->left;
                }

                if (current->right) {
                    if (prev) {
                        prev->next = current->right;
                    } else {
                        level_start = current->right;
                    }
                    prev = current->right;
                }

                current = current->next;
            }
        }
    }
