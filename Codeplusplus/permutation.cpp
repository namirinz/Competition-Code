#include <iostream>
using namespace std;
const int N = 1e7;
int mem[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem[0] = 1;
    int length = 1;
    int i,j;
    int n,temp,add;
    cin >> n;
    for (int i=2;i<=n;i++){
        add = 0;
        for (int j=0;j<length;j++){
            temp = (i*mem[j])+add;
            mem[j] = temp%10;
            add = temp/10;
            if (temp >= 10){
                if (j == length-1){
                    while (temp >= 10){
                        temp = temp/10;
                        mem[length] = temp;
                        length++;
                    }
                    j = length;
                }
            }
        }
    }
    for (int i=length-1;i>=0;i--){
        cout << mem[i];
    }
    return 0;
}