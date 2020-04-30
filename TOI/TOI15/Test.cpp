#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        bool arr[n] = {0};
        for (int j=0;j<n;j++){
            cout << arr[j] << " ";
        }cout << '\n';
        arr[i] = i;
    }
    return 0;
}