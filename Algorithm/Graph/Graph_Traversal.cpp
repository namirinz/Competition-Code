#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//s == start node
void DFS1(vector<int> G1[],bool DFS_isvisited[],int s){
    for (auto k:G1[s]){
        if (!DFS_isvisited[k]){
            DFS_isvisited[k] = 1; //set to visited
            cout << k << " ";
            DFS1(G1,DFS_isvisited,k);
        }
    }
}

void BFS1(vector<int> G1[],bool BFS1_isvisited[],queue<int> q){
    int f;
    while(!(q.empty())){
        f = q.front();
        q.pop();
        if (BFS1_isvisited[f] == true){
            continue;
        }
        BFS1_isvisited[f] = true;
        cout << f << " ";
        for (auto k : G1[f]){
            if (BFS1_isvisited[k] == false) q.push(k);
        }
    }
}

void makeGraph1(vector<int> G1[],int e){
    int v1,v2;
    for (size_t i=0;i<e;i++){
        cin >> v1 >> v2;
        G1[v1].push_back(v2);
        G1[v2].push_back(v1);
    }
}

void printGraph1(vector<int> G1[],int n){
    for (size_t i=0;i<n;i++){
        cout << "Vertex " << i << " : ";
        for (auto k:G1[i]) cout << k << " ";
        cout << endl;
    }
}

int main(){
    int n,e;
    //n == number of nodes/vertex, e == number of edges
    cin >> n >> e;
    vector<int> G1[n];
    queue<int> q1;
    
    bool DFS_isvisited[n] = {0}; //0 == not visited ,1 == visited
    bool BFS_isvisited[n] = {0};
    
    
    makeGraph1(G1,e);
    printGraph1(G1,n);
    cout << "DFS G1 : "<< " "; DFS1(G1,DFS_isvisited,0);
    q1.push(0);
    cout << endl << "BFS G1 : "; BFS1(G1,BFS_isvisited,q1);
    return 0;
}