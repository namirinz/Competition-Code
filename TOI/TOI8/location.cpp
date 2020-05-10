/*
    https://www.proprog.ml/tasks/toi8_location/descs/279
*/
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int main(){
    int n,m,k;
    int i,j;
    int num;
    cin >> n >> m >> k;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            cin >> num;
            arr[i][j] = arr[i-1][j]+arr[i][j-1]+num-arr[i-1][j-1];
        }
    }
    int myMax = INT_MIN;
    for (i=k;i<=n;i++){
        for (j=k;j<=m;j++){
            myMax = max(myMax,arr[i][j]-arr[i-k][j]-arr[i][j-k]+arr[i-k][j-k]);
        }
    }
    cout << myMax;

    return 0;
}