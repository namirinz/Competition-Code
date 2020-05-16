#include <bits/stdc++.h>
using namespace std;
int n,total = 0;
int num1,num2,num;
int main(){
    priority_queue<int,vector<int>,greater<int>> base;
    priority_queue<int> height;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&num);
        height.push(num);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&num);
        base.push(num);
    }
    priority_queue<int,vector<int>,greater<int>> Q;
    while (!base.empty()){
        num1 = height.top()+base.top();
        height.pop();
        base.pop();
        Q.push(num1);
    }
    
    num1 = Q.top();
    Q.pop();
    while(!Q.empty()){
        num2 = Q.top();
        Q.pop();
        total += (num2-num1);
        num1 = num2;
    }
    printf("%d",total);

    return 0;
}