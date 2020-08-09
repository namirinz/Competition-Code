#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int block[m+1];
    char arr[n+1][m+1];
    vector<int> place(m+1, n);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %c",&arr[i][j]);
            if (arr[i][j] == 'O'){
                place[j] = min(place[j], i);
            }
        }
    }
    for (int i=0;i<m;i++){
        scanf("%d",&block[i]);
        if (place[i]-block[i] < 0){
            block[i] = place[i];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (block[j] != 0 && i == place[j]-block[j]){
                printf("#");
                block[j]--;
            }
            else printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
