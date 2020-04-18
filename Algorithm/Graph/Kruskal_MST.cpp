#include <bits/stdc++.h>
using namespace std;
//tuple Weigthed, u, v
typedef vector<tuple<int,int,int>> viii;

const int N = 100;
viii edges;
vector<int> p(N);

//12-22 lines == union find disjoint set

int findParent(int u){
    if (p[u] == u) return u;
    return p[u] = findParent(p[u]);
}

void unionSet(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if (u == v) return;
    p[u] = v;
}


vector<tuple<int,int,int>> path;
void Kruskal(){
    sort(edges.begin(),edges.end());
    int sum = 0;
    for (auto k: edges){
        int v1 = get<1>(k);
        int v2 = get<2>(k);
        if (findParent(v1) == findParent(v2)) continue;
        path.push_back(make_tuple(get<0>(k),v1,v2));
        sum += get<0>(k);
        unionSet(v1,v2);
    }
    
    cout << sum << endl;
    for (auto k: path) cout << get<0>(k) << " " << get<1>(k) << " " << get<2>(k) << endl;
}

void makeGraph(int e){
    int v1,v2,w;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2 >> w;
        p[v1] = v1;
        p[v2] = v2;
        edges.push_back(make_tuple(w,v1,v2));
        edges.push_back(make_tuple(w,v2,v1));
    }
}

int main(){
    int n,e;
    cin >> n >> e;
    makeGraph(e);
    Kruskal();
    return 0;
}
