#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> iii;

int p[200001];
int rnk[200001];
int findRoot(int u){
    if (p[u] == u) return u;
    else {
        return p[u] = findRoot(p[u]);
    }
}

void unionSet(int a,int b){
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    
    if (rnk[a] > rnk[b]){
        rnk[a] += rnk[b];
        p[b] = a;
    }else {
        rnk[b] += rnk[a];
        p[a] = b;
    }
}

bool comp(iii &a, iii &b){
    return get<0>(a)>get<0>(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<iii> edges;
    int n,m;
    cin >> n >> m;

    for (int i=0;i<=n;i++){
        p[i] = i;
        rnk[i] = 1;
    }

    int v1,v2;
    long long int w;
    for (int i=0;i<=n;i++) p[i] = i;
    for (int i=0;i<m;i++){
        cin >> v1 >> v2 >> w;
        edges.push_back(make_tuple(w,v1,v2));
    }

    sort(edges.begin(),edges.end(),comp);
    long long int dist = 0;
    for (auto k: edges){
        int d = get<0>(k);
        int n1 = get<1>(k);
        int n2 = get<2>(k);

        if (findRoot(n1) == findRoot(n2)) continue;
        dist += d-1;
        unionSet(n1,n2);
    }
    cout << dist;
    return 0;
}