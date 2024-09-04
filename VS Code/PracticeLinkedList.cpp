#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;
    LinkedList() {
        this->head = NULL;
    }

    void insertAtBeginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node(data);
        if(this->head == NULL) {
            this->head = new_node;
            return;
        }
        Node* last = this->head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }

    void display() {
        Node* temp = this->head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertLast(int x) {
        
    }
};

LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2) {
    int carry = 0;
    Node* p1 = l1->head;
    Node* p2 = l2->head;

    LinkedList result;

    while(p1 != NULL || p2 != NULL) {
        int sum = carry;
        if(p1 != NULL) {
            sum+=p1->data;
            p1 = p1->next;
        }
        if(p2 != NULL) {
            sum+=p2->data;
            p2 = p2->next;
        }
        carry = sum / 10;
        result.insertAtEnd(sum % 10);
    }
    if(carry > 0) {
        result.insertAtEnd(carry);
    }
    return &result;
}
