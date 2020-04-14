#include <iostream>
using namespace std;
int mem[10000000];
int fib(int n){
    mem[1] = 1;
    mem[2] = 1;
    for (int i=3;i<=n;i++){
        mem[i] = mem[i-1]+mem[i-2];
    }
    return mem[n];
}

int main(){
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}