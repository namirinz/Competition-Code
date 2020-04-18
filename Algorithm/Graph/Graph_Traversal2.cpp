#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(vector<pair<int,int>> G[],int e){
	int v1,v2,w;
	for (size_t i=0;i<e;i++){
		cin >> v1 >> v2 >> w;
		G[v1].push_back(make_pair(v2,w));
		G[v2].push_back(make_pair(v1,w));
	}
}

void printGraph(vector<pair<int,int>> G[],int n){
	for (size_t i=0;i<n;i++){
		cout << "vertex " << i << " : ";
		for (auto k: G[i]) cout << k.first << "," << k.second << " ";
		cout << endl;
	}
}

void DFS(vector<pair<int,int>> G[],bool DFS_isvisited[],int s){
	for (auto k: G[s]){
		if (!DFS_isvisited[k.first]){
			cout << s << "->";
			DFS_isvisited[k.first] = true;
			cout << k.first << "," << k.second << " ";
			DFS(G,DFS_isvisited,k.first);
		}
	}
}

void BFS(vector<pair<int,int>> G[],bool BFS_isvisited[],queue<pair<int,int>> q){
	pair<int,int> f;
	while (!(q.empty())){
		f = q.front();
		q.pop();
		if (BFS_isvisited[f.first] == true){
            continue;
        }
		BFS_isvisited[f.first] = true;
		cout << f.first << "," << f.second << " " ;
		for (auto k: G[f.first]){
			if (BFS_isvisited[k.first] == false){
				q.push(make_pair(k.first,k.second));
			}
		}
	}
}

int main(){
	int v,e;
	cin >> v >> e;

	vector<pair<int,int>> G[v];
	bool DFS_isvisited[v] = {false};
	bool BFS_isvisited[v] = {false};
	queue<pair<int,int>> q;

	makeGraph(G,e);
	printGraph(G,v);
	
	DFS(G,DFS_isvisited,0);
	cout << endl;
	q.push(make_pair(5,0));
	BFS(G,BFS_isvisited,q);

	return 0;
}