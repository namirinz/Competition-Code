#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    unsigned short int n,myMin1,myMin2;
    char s;
    cin >> n;
    myMin2 = n;
    for (int i=0;i<n;i++){
        cin >> s;
        if (s == '#'){
            myMin1 = max(i,n-i-1);
        }
        myMin2 = min(myMin1,myMin2);
    }
    cout << myMin2;
    return 0;
}