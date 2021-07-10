#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int palindrome(int x){
  string num = to_string(x);
  int len_str = num.length();
  cout << "string length: " << len_str << endl;
  for (int i=0;i<len_str/2;i++){
    char fi = num[i], ls = num[len_str-1-i];
    cout << fi << " " << ls << endl;
    if (fi != ls) return false;
  }
  return true;
}

int main(){
  int num;
  scanf("%d", &num);
  int ans = palindrome(num);
  printf("%s", ans ? "true": "false");
  return 0;
}
