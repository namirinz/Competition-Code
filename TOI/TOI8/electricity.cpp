#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    deque<pair<int, int>> Q;
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n + 1];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Q.push_back(make_pair(arr[0], 0));
    for (int i = 1; i < n; i++){
        if (i - Q.front().second > k){
            Q.pop_front();
        }
        while (arr[i] + Q.front().first < Q.back().first){
            Q.pop_back();
        }

        Q.push_back(make_pair(arr[i] + Q.front().first, i));
    }
    printf("%d", Q.back().first);
    return 0;
}