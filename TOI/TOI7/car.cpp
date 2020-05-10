/*
    https://www.proprog.ml/tasks/toi7_car/descs/263
*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

bool isvisited[101][41];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,t;
  cin >> m >> n >> t;
  int arr[t][m];
  for (int i=0;i<t;i++) for (int j=0;j<m;j++) cin >> arr[i][j];
  queue<tuple<vector<int>,int,int,int>> Q;
  vector<int> path;

  Q.emplace(path,0,n-1,-1);
  while (!Q.empty()){
    vector<int> arr2 = get<0>(Q.front());
    int lev = get<1>(Q.front());
    int x = get<2>(Q.front());
    int y = get<3>(Q.front());

    Q.pop();   

    if (lev == t){
      for (auto k : arr2) cout << k << "\n";
      break;
    }
    if (isvisited[y][x] && y != -1) continue;
    if (y != -1) isvisited[y][x] = true;

    if (!isvisited[y+1][x-1] && x>0 && arr[y+1][x-1] == 0){
      arr2.push_back(1);
      Q.emplace(arr2,lev+1,x-1,y+1);
      arr2.pop_back();
    }
    if (!isvisited[y+1][x+1] && x<m-1 && arr[y+1][x+1] == 0){
      arr2.push_back(2);
      Q.emplace(arr2,lev+1,x+1,y+1);
      arr2.pop_back();
    }
    if (!isvisited[y+1][x] && arr[y+1][x] == 0){
      arr2.push_back(3);
      Q.emplace(arr2,lev+1,x,y+1);
    }
  }
  return 0;
}