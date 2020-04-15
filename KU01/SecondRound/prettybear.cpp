#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short int n,a,b,count = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        if ((a >= 100 & a <= 750) && b >= 80){
            count++;
        }
    }
    cout << count;
    return 0;
}