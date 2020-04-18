#include <iostream>
using namespace std;

bool isnotPrime[1000000];
void sieveoferathonis(int n){
    for (int i=2;i*i<=n;i++){
        if (!isnotPrime[i]){
            for (int j = i*i; j <= n ; j += i){
                isnotPrime[j] = true;        
            }
        }
    }
    for (int i=2;i<=n;i++) {
        if (!isnotPrime[i]) cout << i << " ";
    }
}

int main(){
    int n;
    cin >> n;
    sieveoferathonis(n);
    return 0;
}