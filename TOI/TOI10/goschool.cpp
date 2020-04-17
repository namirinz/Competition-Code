#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mem[55][55];
ll dist(int x,int y){
    for (int i=1;i<=y;i++){
        for (int j=1;j<=x;j++){
            if (mem[i][j] == 0){
                if ( j == 1) mem[i+1][j] = 0;
                if ( i == 1) mem[i][j+1] = 0;
            }else if (i == 1|| j == 1) mem[i][j] = 1;
            else mem[i][j] = mem[i-1][j]+mem[i][j-1];
        }
    }
    return mem[y][x];
}

int main(){
    memset(mem,-1,sizeof(mem));
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);;
    int x,y;
    for (int i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        mem[y][x] = 0;
    }
    printf("%lld",dist(m,n));
    return 0;
}