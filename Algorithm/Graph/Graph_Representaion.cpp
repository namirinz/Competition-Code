#include <iostream>
#include <vector>
using namespace std;

void makeGraph1(vector<int> G1[],int e){
    int v1,v2;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2;
        G1[v1].push_back(v2);
    }
}

void printGraph1(vector<int> G1[],int n){
    for (size_t i=0;i<n;i++){
        cout << "Vertex " << i << " : ";
        for (auto k:G1[i]) cout << k << " ";
        cout << endl;
    }
}

void makeGraph2(vector<pair<int,int>> G2[],int e){
    int v1,v2,w;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2 >> w;
        G2[v1].push_back(make_pair(v2,w));
    }
}

void printGraph2(vector<pair<int,int>> G2[],int n){
    for (size_t i=0;i<n;i++){
        cout << "Veretex " << i << " : ";
        for (auto k:G2[i]) cout << k.first << "," << k.second << " ";
        cout << endl;
    }
}

int main(){
    int n,e;
    //n == number of nodes/vertex, e == number of edges
    cin >> n >> e;
    vector<int> G1[n];
    vector<pair<int,int>> G2[n];

    makeGraph1(G1,e);
    printGraph1(G1,n);

    makeGraph2(G2,e);
    printGraph2(G2,n);
    
    return 0;
}