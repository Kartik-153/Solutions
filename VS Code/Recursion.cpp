#include <bits/stdc++.h>
using namespace std;

void fun6(int );

void fun1(int n) {
    if(n>0) {
        cout << n << " ";
        fun1(n-1);
    }
}

int fun2(int n) {
    if(n>0) {
        return fun2(n-1) + n;
    }
    return 0;
}

int fun3(int n) {
    static int x = 0;
    if(n>0) {
        x++;
        return fun3(n-1)+x;
    }
    return 0;
}

int fun4(int n) {
    int x = 0;
    if(n>0) {
        x++;
        return fun4(n-1) + x;
    }
    return 0;
}

void tree_re(int n) {
    if(n>0) {
        cout << n << " ";
        tree_re(n-1);
        tree_re(n-2);
    }
} 

void fun5(int n) {
    if(n>0) {
        cout << n << " ";
        fun6(n-1);
    }
}

void fun6(int n) {
    if(n>1) {
        cout << n << " ";
        fun5(n/2);
    }
}

int fun7(int n) {

    if(n>100) {
        return n - 10;
    }
    else {
        return fun7(fun7(n+11));
    }
}

int Power(int n, int r) {
    if(r == 0) {
        return 1;
    }

    else {
        return Power(n,r-1)*n;
    }
}

int Power2(int n, int r) {
    if(r == 0) {
        return 1;
    }
    else if(r%2 == 0) {
        return Power2(n*n, r/2);
    }
    else {
        return n*Power2(n*n, (r-1)/2);
    }
}

double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if(n == 0) {
        return 1;
    }

    r = e(x,n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
}

double e1(int x, int n) {
    static double s;
    if(n==0)
        return s;

    s = 1 + x*s/n;
    return e(x,n-1);
}

double e3(int x, int n) {
    double s = 1;
    int i;
    double num = 1;
    double dem = 1;
    for(i = 1; i <= n; i++) {
        num *= x;
        dem *= i;
        s += num/dem;
    }
    return s;
}

double e4(int x, int n) {
    double s = 1;
    for(; n>0; n--) {
        s = 1 + x*s/n;
    }
    return s;
}

int rfib(int n) {
    if(n <= 1) {
        return n;
    }
    return rfib(n-2) + rfib(n-1);
}

int F[1000];

int mfib(int n) {   // to avoid execessive calls
    if(n<=1) {
        F[n] = n;
        return n;
    }
    else {
        if(F[n-2] == -1) F[n-2] = mfib(n-2);
        if(F[n-1] == -1) F[n-1] = mfib(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
}

int fact(int n) {
    if(n == 0) {
        return 1;
    }
    return n*fact(n-1);
}

int C(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

int c(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    } 
    else {
        return c(n-1,r-1) + c(n-1,r);
    }
}

int main() {
    F[1000] = {-1};
    cout << C(5,2) << endl;
    cout << c(5,2);
    return 0;
}
