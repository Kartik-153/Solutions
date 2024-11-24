#include <bits/stdc++.h>
using namespace std;

void squarePattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 0)
                printf("%3c", i + 64);
            else
                printf("%3c", i + 96);
        }
        cout << "\n";
    }
}

void patternOnesUpperMatrix(int n) {
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= n; c++) {
            if(c <= n - r) printf("%4d", 1);
            else printf("%4d", r);
        }
        cout << "\n";
    }
}

void pattern10(int n) {
    char ch = 'A';
    int r, c;

    for(r = 1; r <= n; r++) {
        for(c = 1; c <= n; c++) {
            if(r == 1 || r == n || c == 1 || c == n) printf("* ");
            else printf("%c ", ch++);
            if(ch > 'Z') ch = 'A';
        }
        cout << "\n";
    }
}

void patternPyramid(int n) {
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= r; c++) {
            cout << "* " ;
        }
        cout << "\n";
    }
}

void halftNumberPyramid(int n) {
    for(int r = 1; r <= n; r++) {
        for(int c = r; c >= 1; c--) {
            cout << c << " ";
        }
        cout << "\n";
    }
}

int main() {
    halftNumberPyramid(1000000);
    return 0;
}