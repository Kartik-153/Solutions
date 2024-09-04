#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class NodeOperation {
    public:
        void pushNode(class Node** head_ref, int data_val) {
            class Node *new_node = new Node();
            new_node->data = data_val;
            new_node->next = *head_ref;
            *head_ref = new_node;
        }

        void printNode(class Node *head) {
            while(head != NULL){
                cout << head->data << "->";
                head = head->next;
            }
            cout << "NULL" << endl;
        }

        void printMiddle(class Node *head) {
            
            Node *slow_ptr = head;
            Node *fast_ptr = head;

            if(head != NULL) {
                while(fast_ptr != NULL && fast_ptr->next != NULL) {
                    fast_ptr = fast_ptr->next->next;
                    slow_ptr = slow_ptr->next;
                }
                cout << slow_ptr->data;
            }
        }

};

int main() {
    class Node *head = NULL;
    class NodeOperation *item = new NodeOperation;

    for(int i = 5; i > 0; i--) {
        item->pushNode(&head, i);
        item->printNode(head);
        item->printMiddle(head);
    }
    return 0;
}