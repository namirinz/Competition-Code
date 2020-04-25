#include <bits/stdc++.h>
using namespace std;
int mem[10000000];
int coinChangeMEM(int n,vector<int> coin){
    int ans = INT_MAX;
    if (n == 0) return 0;
    if (mem[n]) return mem[n];
    for (auto k: coin){
        if (n >= k){
            mem[n] = min(ans,1+coinChangeMEM(n-k,coin));
            ans = mem[n];
        }
    }
    return mem[n];
}

int coinChangeTAB(int n,vector<int> coin){
    mem[0] = 0;
    for (int i=1;i<=n;i++){
        int ans = INT_MAX;
        for (auto k: coin){
            if (i >= k){
                mem[i] = min(ans,mem[i-k]+1);
                ans = mem[i];
            }
        }
    }
    return mem[n];
}

int main(){
    vector<int> coin;
    int n,l;
    cin >> n >> l;
    int num;
    for (int i=0;i<l;i++){
        cin >> num;
        coin.push_back(num);
    }
    cout << coinChangeMEM(n,coin) << "\n";
    cout << coinChangeTAB(n,coin);
    return 0;
}