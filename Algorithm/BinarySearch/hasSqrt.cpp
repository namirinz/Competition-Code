/*
    Find if square root of n
    is integer (has square root)
    by using binary search
    
    Time Complexity: O(log n)

*/

#include <iostream>
using namespace std;
int n;

bool hasSqrt(int left,int right,int mid){
    if (mid == left) return false;
    else if (mid*mid == n) return true;
    else if (mid*mid < n){
        left = mid;
    }else {
        right = mid;
    }
    hasSqrt(left,right,left+((right-left)/2));
}

int main(){
    cin >> n;
    if (hasSqrt(1,n,1+((n-1)/2))){
        cout << "Has square root";
    }else {
        cout << "Doesn't has square root"
    }
    return 0;
}