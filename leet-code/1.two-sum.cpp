#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> vi, int tar){
  vector<int> ans(2);
  int size_vi = vi.size();
  for (int i=0;i<size_vi;i++){
    for (int j=i+1;j<size_vi;j++){
      if (vi[i] + vi[j] == tar){
        ans[0] = i;
        ans[1] = j;
        return ans;
      }
    }
  }
  return ans;
}

int main(){
  int n, num, tar;
  vector<int> vi;
  printf("Insert size of array: ");
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    scanf("%d",&num);
    vi.push_back(num);
  }
  printf("Insert target: ");
  scanf("%d", &tar);
  vector<int> ans = twosum(vi, tar);
  printf("ans: %d %d", ans[0], ans[1]);
  return 0;
}
