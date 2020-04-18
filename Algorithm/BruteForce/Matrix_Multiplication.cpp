#include <iostream>
using namespace std;
int main(){
    int n,m;
    int a,b;
    cin >> n >> m;
    cin >> a >> b;
    
    int arr1[n][m];
    int arr2[a][b];
    //m == a
    int arr3[n][b];
    int total = 0;

    size_t i,j,k,l;
    for (i=0;i<n;i++) for (j=0;j<m;j++) cin >> arr1[i][j];
    for (i=0;i<a;i++) for (j=0;j<b;j++) cin >> arr2[i][j];

    for (i=0;i<n;i++){
        for (j=0;j<b;j++){
            total = 0;
            for (k=0;k<m;k++){
                total = total+(arr1[i][k]+arr2[k][j]);
            }
            arr3[i][j] = total; 
        }    
    }
    for (i=0;i<n;i++){
        for (j=0;j<b;j++){
            cout << arr3[i][j] << ' ';
        }cout << endl;
    }

    return 0;
}