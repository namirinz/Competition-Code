#include <bits/stdc++.h>
using namespace std;
int N;
float L, W;
int ans = 0;
int main(){
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    scanf("%f %f",&L,&W);
    if (W <= (75*L)/100) {
      ans += 5;
      //printf(" 5 ");
    }
    else {
      ans += 3;
      //printf(" 3 ");
    }
   
  }
  printf("%d",ans);
  return 0;
}
