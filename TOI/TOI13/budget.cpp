/*
    https://www.proprog.ml/tasks/toi13_budget/descs/12573
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii,vii,greater<ii>> PQ;


int main(){
    int ans1,ans2,ans3;
    int n,m;
    scanf("%d %d",&n,&m);
    int s,f,v;
    scanf("%d %d %d",&s,&f,&v);
    
    vii G[n+1];
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&ans1,&ans2,&ans3);
        G[ans1].emplace_back(ans2,ans3);
        G[ans2].emplace_back(ans1,ans3);
    }
    //ans1 == node that nearest to finsih node
    //ans2 == distance from start node to ans1
    //ans3 == distance from ans1 to finish
    ans1 = INT_MAX; ans2 = INT_MAX; ans3 = INT_MAX;

    PQ Q1;
    vector<int> dist1(n+1,INT_MAX);
    dist1[s] = 0;
    Q1.emplace(0,s);
    while (!(Q1.empty())){
        int d1 = Q1.top().first;
        int v1 = Q1.top().second;
        Q1.pop();

        if (v1 == f){
            ans1 = f;
            ans2 = dist1[v1];
            ans3 = 0;
            break;
        }

        if ( d1 > dist1[v1]) continue;

        for (auto k: G[v1]){
            int n1 = k.first;
            int w1 = k.second;
            
            if (dist1[v1] + w1 > v){
                if ( n1 == f){
                    if ( w1 == ans3 && v1 < ans1 ||w1 < ans3 ){
                        ans1 = v1;
                        ans2 = dist1[v1];
                        ans3 = w1;
                    }
                }
                PQ Q2;
                vector<int> dist2(n+1,INT_MAX);
                dist2[v1] = 0;
                Q2.emplace(0,v1);
                while (!(Q2.empty())){
                    int d2 = Q2.top().first;
                    int v2 = Q2.top().second;

                    Q2.pop();

                    if (v2 == f){
                        if ( dist2[v2] == ans3 && v1 < ans1 || dist2[v2] < ans3){
                            ans1 = v1;
                            ans2 = dist1[v1];
                            ans3 = dist2[v2];
                        }
                    }

                    if (d2 > dist2[v2]) continue;

                    for (auto l : G[v2]){
                        int n2 = l.first;
                        int w2 = l.second;

                        if (dist2[v2]+w2 > ans3){continue;}
                        else if (dist2[v2]+w2 < dist2[n2]){
                            dist2[n2] = dist2[v2]+w2;
                            Q2.emplace(dist2[n2],n2);
                        }
                    }
                }
            }

            else if ( dist1[v1]+w1 < dist1[n1]){
                dist1[n1] = dist1[v1]+w1;
                Q1.emplace(dist1[n1],n1);
            }
        }
    }

    printf("%d %d %d",ans1,ans2,ans3);
    return 0;
}