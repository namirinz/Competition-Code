/*
    https://www.proprog.ml/tasks/toi8_sport/descs/277
*/
#include<iostream>
#include <vector>
using namespace std;
int k;

void rec(vector<bool> match,int win,int lose){
    if ( win == k || lose == k){
        for (auto l : match){
            if ( l == true) printf("W ");
            else printf("L ");
        }
        printf("\n");
    }else {
        match.push_back(true);
        rec(match,win+1,lose);
        match.pop_back();
        match.push_back(false);
        rec(match,win,lose+1);
    }
}

int main(){
    int a,b;
    vector<bool> match;
    scanf("%d %d %d",&k,&a,&b);
    rec(match,a,b);

    return 0;
}