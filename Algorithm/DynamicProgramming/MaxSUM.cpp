     #include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000];
int num_max;

vector<int> path;
int MSCC(int n){
    int temp;
    if (n == 0){
        num_max = arr[0];
        path.push_back(arr[0]);
        return arr[0];
    }else {
        temp = max(MSCC(n-1)+arr[n],arr[n]);
        num_max = max(temp,num_max);
        if (num_max == arr[n]){
            path.clear();
        }
        path.push_back(arr[n]);
        for (auto k :path) cout << k << " ";
        cout << endl;
        return temp;
    }
}

int main(){
    int n;
    cin >> n;
    for (size_t i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << MSCC(n-1) << endl;

    cout << num_max;
    return 0;
}