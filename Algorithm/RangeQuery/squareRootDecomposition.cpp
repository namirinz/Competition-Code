/*
    Space Complexity: O(n)
    Prefix Time Complexity: O(n)
    Find Range Time Complexity: O(q*√n + n)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,q,l,r;
int Decom[N];
int arr[N];
int rootN;

void prefix(){
    int index = 0;
    for (int i=0;i<n;i++){
        if (i % rootN == 0){
            Decom[index] = arr[i];
            index++;
        }else {
            Decom[index] = min(Decom[index],arr[i]);
        }
    }
}

int findRange(int l,int r){
    int myMin = arr[l];
    while (l<=r && l%rootN != 0){
        myMin = min(myMin,arr[l]);
        l++;
    }
    while (l+rootN <= r){
        myMin = min(myMin,Decom[l/rootN]);
        l += rootN;
    }
    while (l <= r){
        myMin = min(myMin,arr[l]);
        l++;
    }
    return myMin;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    rootN = sqrt(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    prefix();
    for (int i=0;i<q;i++){
        cin >> l >> r;
        cout << findRange(l,r);

    }

}