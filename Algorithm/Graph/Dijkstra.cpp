#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii,vii,greater<ii>> PQ;

vii G[1000];
bool isVisited[1000];
int path[1000];
int distance = 0;

void printPath(int n){
    if (path[n] == n){
        cout << n;
        return;
    }else {
        cout << n << " -> ";
        return printPath(path[n]);
    }
}

void Dijkstra(int start,int finish){
    vector<int> dist(1000,100000);
    PQ Q;
    dist[start] = 0;
    Q.emplace(0,start);
    while (!Q.empty()){
        int n1 = Q.top().second;
        Q.pop();
        if (n1 == finish){
            path[n1] = n1;
        }

        if (isVisited[n1]) continue;
        
        isVisited[n1] = true;
        for (auto k : G[n1]){
            int d = k.second;
            int n2 = k.first;
            if (!isVisited[n2] && dist[n1]+d < dist[n2]){
                dist[n2] = dist[n1]+d;
                path[n1] = n2;
                distance += dist[n2];
                Q.emplace(dist[n2],n2);
            }
        }
    }
}

void makeGraph(int e){
    int n1,n2,w;
    for (int i=0;i<e;i++){
        cin >> n1 >> n2 >> w;
        G[n1].emplace_back(n2,w);
        G[n2].emplace_back(n1,w);
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    int s,f;
    cin >> s >> f;
    makeGraph(e);
    Dijkstra(s,f);
    printPath(s);
    return 0;
}