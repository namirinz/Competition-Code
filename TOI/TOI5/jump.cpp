#include <bits/stdc++.h>
using namespace std;
int n,k,num;
vector<int> arr(30005);
int _max = -1;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for (int i=0;i<n;i++){
		num = arr[i];
		int l = upper_bound(arr.begin(),arr.begin()+n,num+k)-arr.begin();
		_max = max(_max,l-1-i);
	}
	printf("%d",_max);
	return 0;
}
