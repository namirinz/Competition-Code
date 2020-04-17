#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int isvisited[105][105];
int level[105][105];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char arr[n+5][m+5];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            scanf(" %c",&arr[i][j]);
        }
    }
    queue<tuple<int,int,int>> Q;
        //level, x, y
    Q.emplace(1,1,1);
    while (!(Q.empty())){
        int lev = get<0>(Q.front());
        int x = get<1>(Q.front());
        int y = get<2>(Q.front());
        Q.pop();
        
        if (level[y][x] == lev){
            printf("%d\n%d %d",lev,y,x);
            break;
        }

        if (isvisited[y][x]) continue;
        isvisited[y][x] = true;
        level[y][x] = lev;
        if (arr[y][x] == 'B'){
            if (y < n && !isvisited[y+1][x]){
                Q.emplace(lev+1,x,y+1);
            }if ( x <  m && !isvisited[y][x+1]){
                Q.emplace(lev+1,x+1,y);
            }
        }else if (arr[y][x] == 'R' && x < m && !isvisited[y][x+1]){
            Q.emplace(lev+1,x+1,y); 
        }
        else if (arr[y][x] == 'D' && y < n && !isvisited[y+1][x] ){
            Q.emplace(lev+1,x,y+1);
        }

        if (x > 0&&(arr[y][x-1] == 'B' || arr[y][x-1] == 'R') && !isvisited[y][x-1]){
            Q.emplace(lev+1,x-1,y);
        }
        if ( y > 0&&(arr[y-1][x] == 'B' || arr[y-1][x] == 'D') && !isvisited[y-1][x]){
            Q.emplace(lev+1,x,y-1);
        }
    }
    return 0;
}