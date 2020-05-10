/*
    https://www.proprog.ml/tasks/toi15_budget/descs/15444
*/
#include <bits/stdc++.h>
using namespace std;

int root[3001]; 

int findRoot(int u){
  if (root[u] == u) return u;
  else return root[u] = findRoot(root[u]);
}

void unionRoot(int a,int b){
  a = findRoot(a);
  b = findRoot(b);
  if (a == b) return;
  root[a] = b;
}

bool comp(const pair<int,int> &v,const int &n){
  return (v.second < n);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i=0;i<=3000;i++){
    root[i] = i;
  }

  int b,e;
  cin >> b >> e;
  vector<tuple<int,int,int>> G;
  int v1,v2,w,op;
  for (int i=0;i<e;i++){
    cin >> v1 >> v2 >> w >> op;
    if (op == 1){
      unionRoot(v1,v2);
    }else {
      G.push_back(make_tuple(w,v1,v2));
    }
  }
  
  vector<pair<int,int>> store;
  int p,length,price;
  cin >> p;
  for (int i=0;i<p;i++){
    cin >> length >> price; //length, price
    store.emplace_back(price,length);
  }
  sort(store.begin(),store.end());

  int len = G.size();
  for (int i=0;i<len;i++){
    int d = get<0>(G[i]);
    for (auto k : store){
      if (k.second >= d){
        d = k.first;
        break;
      }
    }
    get<0>(G[i]) = d;      
  }

  sort(G.begin(),G.end());

  int dist = 0;
  for (auto k: G){
    int w = get<0>(k);
    int n1 = get<1>(k);
    int n2 = get<2>(k);

    if (findRoot(n1) == findRoot(n2)) continue;
      
    unionRoot(n1,n2);
    dist += w;
  }
  
  cout << dist;
  return 0;
}