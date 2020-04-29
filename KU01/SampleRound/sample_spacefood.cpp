#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    int ans = 0;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (ans != -1) ans += arr[i];
        if (ans == m && ans != -1) ans = 0;
        else if (ans > m && ans != -1) ans = max(0,ans-k); 
        else ans = -1;
    }
    cout << ans;
    return 0;
}