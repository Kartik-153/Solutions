#include<bits/stdc++.h>
using namespace std;


int *fucn() {
    int phathon = 0;
    return &phathon;
}
int main() {

    int x = 9;
    int *ptr;
    ptr = &x;
    cout << ptr << endl;
    cout << &x << endl;
    cout << *ptr << endl;
    cout << x << endl;

    cout << fucn() << endl;
    return 0;
}