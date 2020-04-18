#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> vi(2501);

int start = 0, finish = 0, pos_begin = 0;
int kadane(){
    int n = vi.size();
    int local_max = 0;
    int glob_max = INT_MIN;
    for (size_t i=0;i<n;i++){
        //local_max is the total (summation)
        local_max = local_max+vi[i];
        if (local_max < vi[i]){
            local_max = vi[i];
            pos_begin = i;
        }

        if (glob_max < local_max){
            glob_max = local_max;
            start = pos_begin; finish = i; 
        }
    }
    return glob_max;
}

int main(){
    int n;
    cin >> n;
    for (size_t i=0;i<n;i++) cin >> vi[i];
    int num_max = kadane();
    if (num_max <= 0){
        cout << "Empty sequence";
    }else {
        for (size_t i=start;i<=finish;i++) cout << vi[i] << " ";
        cout << endl;
        cout << kadane();
    }
    return 0;
}