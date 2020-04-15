#include <iostream>
#include <queue>
using namespace std;
bool isvisited[35][35];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char arr[n+2][m+2];
    bool check = false;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> WarpQ;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            scanf(" %c",&arr[i][j]);
            if (arr[i][j] == 'A') Q1.emplace(j,i);
            else if (arr[i][j] == 'W') WarpQ.emplace(j,i);
        }
    }
    bool loop = true;
    int ans = 0;
    while(!Q1.empty() || !WarpQ.empty()){

        if (Q1.empty()){
            Q1.emplace(WarpQ.front().first,WarpQ.front().second);
            WarpQ.pop();
        }
        int x = Q1.front().first;
        int y = Q1.front().second;

        Q1.pop();

        if (isvisited[y][x]) continue;
        isvisited[y][x] = true;
        if ( arr[y][x] == '*') ans++;
        
        if ( y > 1 && !isvisited[y-1][x] && arr[y-1][x] != '#'){
            Q1.emplace(x,y-1);
            if (arr[y-1][x] == 'W'){
                check = true;
            } 
        }if ( x > 1 && !isvisited[y][x-1] && arr[y][x-1] != '#'){
            Q1.emplace(x-1,y);
            if (arr[y][x-1] == 'W'){
                check = true;
            } 
        }if ( x < m && !isvisited[y][x+1] && arr[y][x+1] != '#'){
            Q1.emplace(x+1,y);
            if (arr[y][x+1] == 'W'){
               check = true;
            } 
        }if ( y < n && !isvisited[y+1][x] && arr[y+1][x] != '#'){
            Q1.emplace(x,y+1);
            if (arr[y+1][x] == 'W'){
                check = true;
            }
        }

        if (!check && Q1.empty()) break;

    }
    printf("%d",ans);


    return 0;
}