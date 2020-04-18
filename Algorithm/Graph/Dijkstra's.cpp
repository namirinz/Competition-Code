#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int N = 1e8+1;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii G[N];

void makeGraph(int e){
    int v1,v2,w;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2 >> w;
        G[v1].emplace_back(v2,w);
        G[v2].emplace_back(v1,w);
    }
}

void printGraph(int n){
    for (size_t i=0;i<n;i++){
        cout << i << " : ";
        for (auto k: G[i]) cout << k.first << ',' << k.second << " ";
        cout << endl;
    }
}

void showDistance(vector<int> dist,int n){
    cout << "Vertext\t" << "Distance" << endl;
    for (size_t i=0;i<n;i++){
        cout << "  " << i << "\t  " << dist[i] << endl;
    }
}

priority_queue<ii, vii, greater<ii>> pq;
int path[N];
void printPath(int f){
    if (path[f] == -1) return;
    printPath(path[f]);
    cout << path[f] << "->";
}

int Dijkstra(int node,int s,int e){
    vector<int> dist(node+1,N);
    bool isvisited[node+1] = {false};
    //print PATH
    path[s] = -1; 
    pq.emplace(0,s);
    dist[s] = 0;
    int myDist = 0;
    while (!(pq.empty())){
        int d = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if (n == e) return dist[n];
        if (isvisited[n]) continue;
        isvisited[n] = true;
        //if (d > dist[n]) continue;

        for (auto k: G[n]){
            int v = k.first;
            int w = k.second;
            if ((!isvisited[v] && dist[n]+w < dist[v])){ // (!isvisited && dist[n]+w < dist[v])
                dist[v] = dist[n]+w;
                path[v] = n;
                myDist += w;
                pq.emplace(dist[v],v);
            }
        }          
    }
    return 0;
    //showDistance(dist,node);
}

int main(){
    int n,e;
    cin >> n >> e;

    makeGraph(e);
    //printGraph(n);

    int s,end;
    cin >> s >> end;
    cout << Dijkstra(n,s,end) << endl;

    int f;
    //cin >> f;
    printPath(end); cout << end;
}