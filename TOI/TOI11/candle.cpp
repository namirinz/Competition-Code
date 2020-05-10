/*
    https://www.proprog.ml/tasks/toi11_candle/descs/6785
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,m,ans = 0;
    scanf("%d %d",&n,&m);
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    bool isvisited[n+1][m+1];
    char str[n+1][m+1];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            isvisited[i][j] = false;
            scanf(" %c",&str[i][j]);
            if ( str[i][j] == '1'){
                Q1.emplace(i,j);
            }
        }
    }
    while (!(Q1.empty())){
        int i = Q1.front().first;
        int j = Q1.front().second;
        Q1.pop();

        if (isvisited[i][j]) continue;
        isvisited[i][j] = true;
        ans++;

        if (!isvisited[i-1][j-1] && str[i-1][j-1] == '1' && i > 0 && j > 0) Q2.emplace(i-1,j-1);
        if (!isvisited[i-1][j] && str[i-1][j] == '1' && i > 0) Q2.emplace(i-1,j);
        if (!isvisited[i-1][j+1] && str[i-1][j+1] == '1' && i > 0 && j < m) Q2.emplace(i-1,j+1);
        if (!isvisited[i][j-1] && str[i][j-1] == '1' && j > 0) Q2.emplace(i,j-1);
        if (!isvisited[i][j+1] && str[i][j+1] == '1' && j < m) Q2.emplace(i,j+1);
        if (!isvisited[i+1][j-1] && str[i+1][j-1] == '1' && i < n && j > 0) Q2.emplace(i+1,j-1);
        if (!isvisited[i+1][j] && str[i+1][j] == '1' && i < n) Q2.emplace(i+1,j);
        if (!isvisited[i+1][j+1] && str[i+1][j+1] == '1' && i < n && j < m) Q2.emplace(i+1,j+1);

        while (!(Q2.empty())){
            int i1 = Q2.front().first;
            int j1 = Q2.front().second;
            Q2.pop();

            if(isvisited[i1][j1]) continue;
            isvisited[i1][j1] = true;

            if (!isvisited[i1-1][j1-1] && str[i1-1][j1-1] == '1' && i1 > 0 && j1 > 0) Q2.emplace(i1-1,j1-1);
            if (!isvisited[i1-1][j1] && str[i1-1][j1] == '1' && i1 > 0) Q2.emplace(i1-1,j1);
            if (!isvisited[i1-1][j1+1] && str[i1-1][j1+1] == '1' && i1 > 0 && j1 < m) Q2.emplace(i1-1,j1+1);
            if (!isvisited[i1][j1-1] && str[i1][j1-1] == '1' && j1 > 0) Q2.emplace(i1,j1-1);
            if (!isvisited[i1][j1+1] && str[i1][j1+1] == '1' && j1 < m) Q2.emplace(i1,j1+1);
            if (!isvisited[i1+1][j1-1] && str[i1+1][j1-1] == '1' && i1 < n && j1 > 0) Q2.emplace(i1+1,j1-1);
            if (!isvisited[i1+1][j1] && str[i1+1][j1] == '1' && i1 < n) Q2.emplace(i1+1,j1);
            if (!isvisited[i1+1][j1+1] && str[i1+1][j1+1] == '1' && i1 < n && j1 < m) Q2.emplace(i1+1,j1+1);
        }
    }
    printf("%d",ans);
    
    return 0;
}