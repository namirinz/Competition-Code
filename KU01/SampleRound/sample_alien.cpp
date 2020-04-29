#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n,x,y,r;
    cin >> n >> x >> y >> r;
    r = pow(r,2);
    int x1,y1,d;
    int ans = 0;
    for (int i=0;i<n;i++){
        cin >> x1 >> y1;
        d = pow((x1-x),2)+pow((y1-y),2);
        if (d <= r){
            ans++;
        }
    }
    cout << ans;
    return 0;
}