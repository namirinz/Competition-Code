/*
    https://www.proprog.ml/tasks/toi9_pipe/descs/285
*/
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

typedef tuple<int,int,int,int> iiii;
short int state[301][301];
int main(){
    int n,m,num;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    queue<iiii> Start;
    queue<iiii> Path;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %d",&num);
            arr[i][j] = num;
            if (i == 0 && (num == 11 || num == 12 || num == 21 || num == 31)){
                if (state[i][j] != 2)state[i][j] = 1;
                if (j == 0 && num == 31) { Start.emplace(4,0,j,i); state[i][j] = 2;}
                Start.emplace(1,0,j,i);
            }
            if (j == m-1 && (num == 12|| num == 14|| num == 22|| num == 31)){
                if (state[i][j] != 2) state[i][j] = 1;
                if (i == 0 && num == 31) { Start.emplace(1,0,j,i); state[i][j] = 2;}
                Start.emplace(3,0,j,i);
            }
                
            if (i == n-1&& (num == 13||num == 14||num == 21|| num == 31)){
                if (state[i][j] != 2)state[i][j] = 1;
                if (j == 0 && num == 31) {Start.emplace(4,0,j,i); state[i][j] = 2;}
                Start.emplace(2,0,j,i);
            }
            if (j == 0 && (num == 11|| num == 13|| num == 22|| num == 31))
                if (state[i][j] != 2) state[i][j] = 1;
                Start.emplace(4,0,j,i);
        }
    }
    vector<int> ans {0};
    
    while (!Start.empty()){
        int pos1 = get<0>(Start.front());
        int x1 = get<2>(Start.front());
        int y1 = get<3>(Start.front());
        Start.pop();
        if (state[y1][x1] <= 0) continue;
        
        Path.emplace(pos1,0,x1,y1);
        state[y1][x1]--;
        while(!Path.empty()){
            int pos = get<0>(Path.front());
            int lev = get<1>(Path.front());
            int x = get<2>(Path.front());
            int y = get<3>(Path.front());
            
            Path.pop();
            
            if ( y == -1){
                ans[0]++;
                state[y+1][x]--;
                ans.push_back(lev);
                break;
            }else if ( y == n){
                ans[0]++;
                state[y-1][x]--;
                ans.push_back(lev);
                break;
            }else if ( x == -1){
                ans[0]++;
                state[y][x+1]--;
                ans.push_back(lev);
                break;
            }else if ( x == m){
                ans[0]++;
                state[y][x-1]--;
                ans.push_back(lev);
                break;
            }

            if ( pos == 1 && (arr[y][x] == 21 || arr[y][x] == 31)) Path.emplace(1,lev+1,x,y+1);
            else if ( pos == 4 && arr[y][x] == 13) Path.emplace(1,lev+1,x,y+1);
            else if ( pos == 3 && arr[y][x] == 14) Path.emplace(1,lev+1,x,y+1);

            else if ( pos == 1 && arr[y][x] == 11) Path.emplace(3,lev+1,x-1,y);
            else if ( pos == 2 && arr[y][x] == 13) Path.emplace(3,lev+1,x-1,y);
            else if ( pos == 3 && (arr[y][x] == 22 || arr[y][x] == 31)) Path.emplace(3,lev+1,x-1,y);

            else if ( pos == 1 && arr[y][x] == 12) Path.emplace(4,lev+1,x+1,y);
            else if ( pos == 2 && arr[y][x] == 14) Path.emplace(4,lev+1,x+1,y);
            else if ( pos == 4 && (arr[y][x] == 22 || arr[y][x] == 31)) Path.emplace(4,lev+1,x+1,y);

            else if ( pos == 2 && (arr[y][x] == 21 || arr[y][x] == 31)) Path.emplace(2,lev+1,x,y-1);
            else if ( pos == 3 && arr[y][x] == 12) Path.emplace(2,lev+1,x,y-1);
            else if ( pos == 4 && arr[y][x] == 11) Path.emplace(2,lev+1,x,y-1);
            
        }
    }
    printf("%d\n",ans[0]);
    int len = ans.size();
    for (int i = 1;i<len;i++) printf("%d ",ans[i]);
    return 0;
}