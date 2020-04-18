#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
void prime(){
    int i,j;
    if (n >= 2) cout << 2 << "\t";
    vector<int> num = {2};
    for (i=3;i<n;i++){
        for (j=0;j<num.size();j++) if (i%num[j] == 0) break;
        if (j == num.size()){
            if (i>sqrt(n)) num.push_back(i);
            cout << i << "\t";
        }
    }
}
int main(){
    int n;
    cin >> n;
    prime();
}