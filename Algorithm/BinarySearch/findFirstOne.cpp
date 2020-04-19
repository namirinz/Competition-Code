/*
    Find the first index of array 
    that contain 1 by using Binary Search

    Time Complexity: O(log n)
*/
#include <iostream>
using namespace std;
const int N = 1e7;
int n;
int arr[N];

int findFirstOne(int left,int right,int mid){
    if (right-left == 1){
        if (arr[left] == 1) {
            return left+1;
        }
        else {
            return right+1;
        }
    }else if (arr[mid] >= 1){5
        findFirstOne(left,mid,left+((mid-left)/2));
    }else {
        findFirstOne(mid,right,mid+((right-mid)/2));
    }
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << findFirstOne(0,n-1,(n-1)/2);
    return 0;
}