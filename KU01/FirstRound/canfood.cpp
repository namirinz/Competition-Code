#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short int n,count=0,a,b;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        if (a <= 400 && ( b >= 150 && b <= 200)){
            count++;
        }
    }
    cout << count;
    return 0 ;
}