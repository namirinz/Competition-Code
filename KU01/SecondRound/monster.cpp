#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short int n,h,num,myMax=0;
    cin >> n >> h;
    for (int i=0;i<n;i++){
        cin >> num;
        if (num <= h && num > myMax){
            myMax = num;
        }
    }
    cout << myMax;  
    return 0;
}