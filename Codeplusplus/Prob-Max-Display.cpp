#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,num;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> num;
        if (num%2 != 0){
            cout << 7;
            num -= 3;
        }
        for (int j=0;j<num/2;j++){
            cout << 1;
        }
        cout << "\n";
    }
    return 0;
}