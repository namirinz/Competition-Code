#include <iostream>
using namespace std;
int main(){
    int n,m,s;
    int myMax;
    cin >> n >> m >> s;
    int arr[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i=0;i<m;i++){
        myMax = arr[0][i];
        ans++;
        for (int j=1;j<n;j++){
            arr[j][i] += (j*s);
            if (arr[j][i] > myMax){
                ans++;
            }
            myMax = max(myMax,arr[j][i]);
        }
    }
    cout << ans;
    return 0;
}