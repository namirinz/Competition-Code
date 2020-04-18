#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> vi;
vector<int> p(N);

//find the parent of u in vector p
int root(int u){
    if (p[u] == u) return u;
    return p[u] = root(p[u]);
}

bool isSame(int u,int v){
    if (root(u) == root(v)) return true;
    return false;
}

void unionSet(int u,int v){
    u = root(u);
    v = root(v);
    if (u == v) return;
    p[u] = v;
}

int main(){
    int n,x;
    cin >> n;
    for (size_t i=0;i<n;i++){
        cin >> x;
        vi.push_back(x);
        p[x] = x; //Initialize vector
    }
    int a,b;
    while(true){
        cin >> a >> b;
        if ( a == 0 || b == 0) break;
        if (!isSame(a,b)){
            cout << "Not in the same ";
            unionSet(a,b);
        }
        cout << root(a) << " " << root(b) << endl;
    }
    return 0;
}