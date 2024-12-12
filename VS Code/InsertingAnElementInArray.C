#include<stdio.h>
#include<stdlib.h>

void addElement(int *, int, int);

void addElement(int *table, int element, int length) {
    int i = length - 1;
    for(; i > 0 && table[i-1] > element; --i) {
        table[i] = table[i-1];
    }
    table[i] = element;
}

int main() {
    int table[4] = {1,2,3,4};
    addElement(table, -90, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", table[i]);
    }
    return 0;
}