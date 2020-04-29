#include <iostream>
using namespace std;
int main(){
    int l,m,n;
    int start,op;
    int ans;
    cin >> l >> m >> n;
    for (int i=0;i<n;i++){
        start = l;
        ans = 1;
        for (int j=0;j<m;j++){
            cin >> op;
            if (op) start++;
            else start--;

            if (start < 0 || start > l*2){
                ans = 0;
            }
        }
        cout<< ans << "\n";
    }
    return 0;
}