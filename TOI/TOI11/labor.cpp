#include <bits/stdc++.h>
using namespace std;
int n,m;
int num;
int _max = -1,_count=0; 
int fnum;

typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii>> Q;
int main(){
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++){
    scanf("%d",&num);
    Q.push(0,num);
  }
  while (_count != m) {
    
  }

  printf("%d",_max);
  
  return 0;
}
