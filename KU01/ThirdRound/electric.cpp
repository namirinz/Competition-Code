#include <bits/stdc++.h>
using namespace std;
int arr[105];
int min_ans = INT_MAX;
int num = 0;
int main(){
  int N, L;
  scanf("%d %d",&N,&L);
  for (int i=0;i<N;i++){
    int max_arr = INT_MIN;
    arr[0] = 0;
    for (int j=1;j<=L;j++){
      scanf("%d", &arr[j]);
      max_arr = max(arr[j]-arr[j-1], max_arr);
      //printf("%d %d %d\n",max_arr, arr[j-1], arr[j]);
    }
    //printf("\n");
    min_ans = min(max_arr, min_ans);
  }
  printf("%d",min_ans);
  return 0;
}
