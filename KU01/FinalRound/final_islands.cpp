#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> Q;
    int n,k;
    int total;
    cin >> n >> k;
    int num;
    int totalK=0;
    for (int i=0;i<n;i++){
        cin >> num;
        if (num <= 0){
            total = 0;
            for (int j=i;j<n;j++){
                if (j != i) cin >> num;
                if (num > 0){
                    totalK++;
                    i = j;
                    cout  << " its" << total << " " ;
                    Q.push(abs(total));
                    break;
                }else if (j == n-1 && num < 0){
                    Q.push(abs(total+(num-1)));
                    i = j;
                    break;
                }
                total += num-1;
            }
        }else if ( i == 0){
            totalK++;
        }
    }
    int ans = 0;
    int endloop = totalK-k;
    for (int i=0;i<endloop;i++){
        ans += Q.top();
        Q.pop();
    }
    cout << ans;
    return 0;
}