/*
    50/100  TIME LIMIT EXCEEDED :(
*/
int path[2005];
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii,vii,greater<ii>> PQ;

void printPath(int u){
    if (path[u] == u){
        cout << u;
        return;
    }
    printPath(path[u]);
    cout << " -> " << u;
}

typedef long long int lli;
vii G[2005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p,u,e;
    cin >> n >> p >> u >> e;
    int n1,n2,w;
    for (int i=0;i<e;i++){
        cin >> n1 >> n2 >> w;
        G[n1].emplace_back(n2,w);
    }
    int l,h;
    cin >> l;

    for (int i=0;i<l;i++){
        cin >> h;
        PQ Q;
        vector<int> dist(2005,10000000);
        bool isvisited[2005] = {0};
        Q.emplace(0,p);
        int ans = 0;
        dist[p] = 0;
        //bool finish = false;
        while (!Q.empty()){ 

            int v1 = Q.top().second;
            //cout << v1 << " ";
            Q.pop();
            
            if (v1 == u){
                //cout << "\nYES\n";
                printPath(v1);
                ans = dist[v1];
                break;
                //finish = true;
            }

            if (isvisited[v1])  continue;
            isvisited[v1] = true;


            for (auto k: G[v1]){
                int v2 = k.first;
                int d = k.second;
                //cout << v1 << " " << v2 << " " << dist[v1] << " " << dist[v2] << "\n";
                if (!isvisited[v2]){
                    if (v1 == p && dist[v1]+d < dist[v2]){
                        //cout << " hi1 ";
                        dist[v2] = dist[v1]+d;
                        path[v2] = v1; 
                        //ans += dist[v2];
                        Q.emplace(dist[v2],v2);
                    }else if (v1 != p && dist[v1]+d+h < dist[v2]) {
                       // cout << " hi2 ";
                        dist[v2] = dist[v1]+d+h;
                        path[v2] = v1;
                        //ans += dist[v2];
                        Q.emplace(dist[v2],v2);
                    }
                }
            }
        }
        cout << "\n" << ans << " ";
    }
    return 0;
}