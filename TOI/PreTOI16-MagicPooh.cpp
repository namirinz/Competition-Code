/*
    https://www.codecube.in.th/task/228
*/
#include <bits/stdc++.h>
using namespace std;

bool isvisited[100002];

typedef unsigned long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef priority_queue<ii,vii,greater<ii>> PQ;

PQ Q;
vector<pair<lli,lli>> G[100002];
vector<tuple<lli,lli,bool>> dist(100002,{ULLONG_MAX,0,false});

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli n,m,k,t;
    cin >> n >> m >> k >> t;
    lli n1,n2;
    lli w,ansDist=0;
    PQ Q; //dist, node
    for (int i=0;i<m;i++){
        cin >> n1 >> n2 >> w;
        G[n1].emplace_back(n2,w);
        G[n2].emplace_back(n1,w);
    }
    Q.emplace(0,1); // distance, startnode
    dist[1] = {0,0,false};// distance, maxDist
    while (!Q.empty()){
        n1 = Q.top().second;
        Q.pop();
        if (isvisited[n1]) continue;
        isvisited[n1] = true;
        
        for (auto l:G[n1]){
            n2 = l.first;
            w = l.second;
            lli weight = get<0>(dist[n1]);
            lli myMax = get<1>(dist[n1]); //max 
            bool isUse = get<2>(dist[n1]);

            if (w <= k){
                if (!isvisited[n2] && weight+w < get<0>(dist[n2])){
                    dist[n2] = {weight+w,myMax,isUse};
                    Q.emplace(get<0>(dist[n2]),n2);
                }
            }else {
                if (w > myMax){
                    if (!isvisited[n2] && isUse && weight+myMax < get<0>(dist[n2])){ //isUse
                        dist[n2] = {weight+myMax,w,isUse};
                        Q.emplace(get<0>(dist[n2]),n2);
                    }
                    else if (!isvisited[n2] && !isUse && weight+k < get<0>(dist[n2])){
                        dist[n2] = {weight+k,w,true};
                        Q.emplace(get<0>(dist[n2]),n2);
                    }
                }else {
                    if  (!isvisited[n2] && weight + w < get<0>(dist[n2])){
                        dist[n2] = {weight+w,myMax,isUse};
                        Q.emplace(get<0>(dist[n2]),n2);
                    }
                }
            }
        }
    }lli ans = get<0>(dist[n]);
            if (ans <= t){
                cout << "Happy Winnie the Pooh :3\n" << ans;
            }else {
                cout << "No Honey TT";
            }

    return 0;
}