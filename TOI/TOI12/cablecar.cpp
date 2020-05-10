/*
    https://www.proprog.ml/tasks/toi12_cablecar/descs/6792
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii,vii,greater<ii>> PQ;
bool isvisited[2501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int v1,v2,w;
    vii G[n+1];
    for (int i=0;i<m;i++){
        cin >> v1 >> v2 >> w;
        G[v1].emplace_back(v2,w);
        G[v2].emplace_back(v1,w);
    }
    int s,f,value;
    cin >> s >> f >> value;
    vector<int> dist(n+1,99999999);
    PQ Q;
    Q.emplace(0,s);
    dist[s] = 0;
    while (!Q.empty()){
        int v = Q.top().second;
        Q.pop();

        for (auto k: G[v]){
            int n1 = k.first;
            int d = k.second;
            if ( value%(d-1) == 0) d = value/(d-1);
            else d = (value/(d-1))+1;
            if (d < dist[v]) d = dist[v];
            if (d < dist[n1]){
                dist[n1] = d;
                Q.emplace(dist[n1],n1);
            }
        }
    }
    cout << dist[f];
    return 0;
}