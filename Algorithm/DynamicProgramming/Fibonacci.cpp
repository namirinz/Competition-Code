//Memoization
#include <iostream>
using namespace std;

int mem[10000000];

int fibMEM(int n){
    mem[1] = 1;
    mem[2] = 1;
    if (n < 1) return n;
    if (mem[n]) return mem[n];
    return mem[n] = fibMEM(n-1)+fibMEM(n-2);
}
int fibTAB(int n){
    mem[0] = 0;
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
    cout << fibMEM(n) << "\n";
    cout << fibTAB(n);
    return 0;
}