#include <iostream>
using namespace std;
int main(){
    int p;
    int num;
    cin >> p;
    int l1 = p, l2 =p;
    p += p;
    int count1=0, count2 = 0;
    for (int i=0;i<p;i++){
        cin >> num;
        if (num%2 == 0){
            count2 = 0;
            count1++;
            if (count1 >= 3) l2 -= 3;
            else l2--;
        }else {
            count1 = 0;
            count2++;
            if (count2 >= 3) l1 -= 3;
            else l1--;
        }
        if (l1 <= 0 ) {
            cout << 1 << endl << num; 
            break;
        }
        else if (l2 <= 0) {
            cout << 0 << endl << num; 
            break;
        }
    }
    return 0;
}