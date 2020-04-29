#include <iostream>
using namespace std;
int main(){
    int n,m;
    int dr,now = 0;
    cin >> n >> m;
    int arr[n+1];
    arr[0] = 0;
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for (int i=0;i<m;i++){
        cin >> dr;
        if (now != n)now += dr;

        if (now >= n ) now = n;
        else if (arr[now] != 0){
            now += arr[now];
            if (now >= n ) now = n;
            else if (now <= 0) now = 0;
        }
    }
    cout << now;
    return 0;
}