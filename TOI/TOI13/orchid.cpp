#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000005],n;

int LIS(){
    vector<int> T;
    T.push_back(arr[0]);
    int length = 1;
    for (int i=1;i<n;i++){
        auto k = upper_bound(T.begin(),T.end(),arr[i]);
        if (arr[i] >= T[length-1]){
            T.push_back(arr[i]);
            length++;
        }
        else {
            *k = arr[i];
        }
    }
    return length;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    int len = LIS();
    printf("%d",n-len);
    return 0;
}