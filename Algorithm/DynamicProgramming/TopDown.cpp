//Memoization
#include <iostream>
using namespace std;

int f[100] = {0};

int fib(int n){
    f[1] = 1;
    f[2] = 1;
    if (n < 1) return n;
    if (f[n] != 0){
        return f[n];
    }
    return f[n] = fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}