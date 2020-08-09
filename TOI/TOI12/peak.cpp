#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[5000000];
vector<int> vi;
int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    for (int i=0;i<n;i++){
        if (i == 0 && arr[i] > arr[i+1]){
            vi.push_back(arr[i]);
        }
        else if (i == n-1 && arr[i] > arr[i-1]){
            vi.push_back(arr[i]);
        }
        else if (i != n-1 && 1 != 0 && arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            vi.push_back(arr[i]);
        }
    }
    sort(vi.begin(),vi.end());
    vi.resize(unique(vi.begin(),vi.end())-vi.begin());
    int len = vi.size();
    if (len >= k) reverse(vi.begin(), vi.end());

    if (len == 0) printf("-1");
    else {
        for (int i=0;i<min(len,k);i++){
            printf("%d\n",vi[i]);
        }
    }

    return 0;
}
