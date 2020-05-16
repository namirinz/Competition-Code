#include <iostream>
using namespace std;
int arr[] = {9,6,2,7,1234,65,12,1};

int merge(int left,int mid,int right){
  int i = left;
  int j = mid;
  int k = left;
  int inversion = 0;

  int T[100];
  while (i <= mid-1 && j <= right){
    if (arr[i] < arr[j]){
      T[k++] = arr[i++];
    }else {
      T[k++] = arr[j++];

      inversion += (mid-i);
    }
  }
  while (i <= mid-1){
    T[k++] = arr[i++];
  }
  while (j <= right){
    T[k++] = arr[j++];
  }
  for (int loop=left;loop<=right;loop++){
    arr[loop] = T[loop];
  }
  return inversion;
}

int mergeSort(int left,int right){
  int mid = (left+right)/2;
  int inversion = 0;
  if (right > left){
    inversion = mergeSort(left,mid);
    inversion += mergeSort(mid+1,right);

    inversion += merge(left,mid+1,right);
  }
  return inversion;
}

int main(){
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << mergeSort(0,size-1) << '\n';
  for (int i=0;i<size;i++){
    cout << arr[i] << ' ';
  }
  return 0;
}