#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char arr[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cout << "\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (arr[i][j] == '#'){
                arr[i][j] = '.';
                for (int k = j; k >= 0; k--){
                    if (k == 0 || arr[i][k-1] == '#'){
                        arr[i][k] = '#';
                        break;
                    }
                }
            }
        }
    }

    for (int i=n-1;i>=0;i--){
        for (int j=0;j<n;j++){
            if (arr[i][j] == '#'){
                arr[i][j] = '.';
                for (int k=i;k<n;k++){
                    if (k == n-1 || arr[k+1][j] == '#'){
                        arr[k][j] = '#';
                        break;
                    }
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << arr[i][j];
        }cout << "\n";
    }
    return 0;
}