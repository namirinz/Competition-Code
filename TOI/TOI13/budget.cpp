#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> PQ;

PQ Q1, Q2;
vii G[10005];
vector<int> dist1(10005,INT_MAX), dist2(10005, INT_MAX);
tuple<int,int,int> ans = make_tuple(INT_MAX, INT_MAX, INT_MAX); // node, distance(s->e), distance(e->s)
bool isvisited1[10005], isvisited2[10005];
bool reach = false;

int v1_1, v2_1, w_1;
int v1_2, v2_2, w_2;

void make_graph(int m){
    int v1,v2,w;
    for (int i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        G[v1].emplace_back(v2, w);
        G[v2].emplace_back(v1, w);
    }
}

void Dijkstra2(int s,int e){
    dist2[s] = 0;
    Q2.emplace(0, s);
    while( !Q2.empty() ){
        v1_2 = Q2.top().second;
        Q2.pop();
        if (isvisited2[v1_2]) continue;
        isvisited2[v1_2] = true;
        //if (v1_2 == e) break;

        for (auto k:G[v1_2]){
            v2_2 = k.first;
            w_2 = k.second;
            if (!isvisited2[v2_2] && dist2[v1_2]+w_2 < dist2[v2_2]){
                dist2[v2_2] = dist2[v1_2]+w_2;
                Q2.emplace(dist2[v2_2], v2_2);
            }
        }
    }
}

void Dijkstra1(int s,int e,int v){
    dist1[s] = 0;
    Q1.emplace(0, s);
    while( !Q1.empty() ){
        v1_1 = Q1.top().second;
        Q1.pop();
        if (isvisited1[v1_1]) continue;
        isvisited1[v1_1] = true;
        if (v1_1 == e){
            //printf("%d %d %d",v1_1,dist1[v1_1],dist2[v1_1]);
            ans = make_tuple(v1_1,dist1[v1_1],dist2[v1_1]);
            break;
        }
        for (auto k : G[v1_1]){
            v2_1 = k.first;
            w_1 = k.second;

            if (!isvisited1[v2_1] && dist1[v1_1]+w_1 <= v && dist1[v1_1]+w_1 < dist1[v2_1]){
                dist1[v2_1] = dist1[v1_1]+w_1;
                Q1.emplace(dist1[v2_1], v2_1);
            }
            else if (!isvisited1[v2_1] && dist1[v1_1]+w_1 > v && dist1[v1_1]+w_1 < dist1[v2_1]){
                //printf(" HELLO SO YEAH %d\n",v1_1);
                if (dist2[v1_1] < get<2>(ans) || dist2[v1_1] == get<2>(ans) && v1_1 < get<0>(ans)){
                    //printf(" hello 1 \n");
                    ans = make_tuple(v1_1, dist1[v1_1], dist2[v1_1]);
                }
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int s,e,v;
    scanf("%d %d %d",&s,&e,&v);

    make_graph(m);

    Dijkstra2(e, s);
    Dijkstra1(s, e, v);

    printf("%d %d %d",get<0>(ans), get<1>(ans), get<2>(ans));
    return 0;
}
