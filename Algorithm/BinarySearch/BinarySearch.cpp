#include <iostream>
using namespace std;
//sorted array
int arr[10000];

int BS(int left,int mid,int right,int key){
    if (arr[mid] == key){
        return mid;
    }
    if (left > right) return -1;
    else {
        if (key < arr[mid]){
            BS(left,(left+mid-1)/2,mid-1,key);
        }else {
            BS(mid+1,(mid+1+right)/2,right,key);
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for (size_t i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << BS(0,(n-1)/2,n-1,k);   
    return 0;
}