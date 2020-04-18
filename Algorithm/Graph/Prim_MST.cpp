//Minimum Spanning Tree with Prim Algorithm
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 100;
vii G[N];

void makeGraph(int e){
    int v1,v2,w;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2 >> w;
        G[v1].emplace_back(v2,w);
        G[v2].emplace_back(v1,w);
    }
}

vector<int> node(N,N);
bool isvisited[N] = {false};

void Prim(int start){
    node[start] = 0;
    priority_queue<pii, vii, greater<pii>> min_pq;
    min_pq.emplace(0,start);
    while(!(min_pq.empty())){
        int d = min_pq.top().first;
        int n = min_pq.top().second;
        min_pq.pop();
        if (isvisited[n]) continue;
        isvisited[n] = true;
        for (auto k: G[n]){
            int v = k.first;
            int w = k.second;
            if( !isvisited[v] && w < node[v]){
                node[v] = w;
                min_pq.emplace(w,v);
            }
        }
    }    
}

int main(){
    int v,e;
    cin >> v >> e;
    makeGraph(e);
    int s;
    cin >> s;
    Prim(s);
    int total=0;
    for (size_t i=0;i<v;i++) total += node[i];
    cout << total;
    return 0;
}