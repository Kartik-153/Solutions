#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t,*last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++) {
        // t = (struct Node *)malloc(sizeof(struct Node));
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void Display1(struct Node* p) {
    if(p!=NULL) {
        cout << p->data << endl;
        Display1(p->next);
    }
}

void Display_rev(struct Node* p) {
    if(p!=NULL) {
        Display_rev(p->next);
        cout << p->data << endl;
    }
}

int count(struct Node *p) {
    int c = 0;
    while(p!=NULL) {
        c+=1;
        p=p->next;
    }
    return c;
}

int RCount(struct Node *p) {
    if(p==0) {
        return 0;
    }
    return RCount(p->next) + 1;
}

int RMAX(struct Node*p){
    int x = 0;
    if(p==0) {
        return INT_MIN;
    }
    else {
        x = RMAX(p->next);
        if(x > p->data)
        return x;
        else 
        return p->data;
    }
}

int MMAX(struct Node*p) {
    int x = __INT32_MAX__;
    while(p) {
        if(p->data > x) {
            x = p->data;
        }
        p = p->next;  
    }
    return x;
}

int sum(struct Node *p) {
    int s = 0;
    while(p) {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node*p) {
    if(p==0) {
        return 0;
    }
    return Rsum(p->next) + p->data;
}

int MMIN(struct Node*p) {
    int x = INT32_MAX;
    while(p) {
        if(x > p->data) {
            x = p->data;
        }
        p = p->next;
    }
    return x;
}

int RMIN(struct Node *p) {
    if(p == 0) {
        return INT32_MAX;
    }
    else {
        int x = RMIN(p->next);
        if(x < p->data) {
            return x;
        }
        else {
            return p->data;
        }
    }
}

struct Node* LSearch(struct Node *p, int key) {
    while(p!=NULL) {
        if(key == p->data) {
            return (p);
        }
        p = p->next;
    }
    return NULL; 
}

struct Node* RLSearch(struct Node *p, int key) {
    if(p == NULL) {
        return NULL;
    }
    if(key == p->data)
    return p;
    return RLSearch(p->next, key);
}

struct Node* ImSearch(Node *p, int key) {
    Node *q = NULL;
    while(p!=NULL) {
        if(key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
    return first;
}

struct Node* Insert_at_first(struct Node* first, int x) {
    struct Node* t = new Node();
    t->data = x;
    t->next = first;
    first = t;
    return first;
}

struct Node* Insert_at_position(struct Node* p, int pos, int x) {
    struct Node* t = new Node();
    t->data = x;
    p = first;
    for(int i = 0; i < pos - 1 && p; i++) {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    return first;
}

void Insert(int pos, int x) {
    Node*t,*p;
    if(pos == 0) {
        t = new Node();
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0) {
        p = first;
        for(int i = 0; i < pos - 1 && p; i++) {
            p = p->next;
        }
        if(p) {
            t = new Node();
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}


int main() {
    int A[] = {3,5,7,10,15,-1,0};
    create(A,7);
    // cout << RMAX(first) << " ";
    // cout << RSearch(first, -1);
    Display(Insert_at_position(first, 4, 984));
 
    return 0;
}