#include <bits/stdc++.h>
using namespace std;
long long int n;

long long int ans;
long long int mem[1000005];
long long int rec(long long int num){
	mem[0] = 0;
	for (long long int i=1;i<=num;++i){
		ans = LLONG_MAX;
		if (i >= 15){
			ans = min(ans,mem[i-15]+3000);
			ans = min(ans,mem[i-5]+1500);
			ans = min(ans,mem[i-2]+800);
			mem[i] = min(ans,mem[i-1]+500);
		}else if ( i >= 5 ){
			ans = min(ans,mem[0]+3000);
			ans = min(ans,mem[i-5]+1500);
			ans = min(ans,mem[i-2]+800);
			mem[i] = min(ans,mem[i-1]+500);
		}else if (i >= 2) {
			ans = min(ans,mem[0]+1500);
			ans = min(ans,mem[i-2]+800);
			mem[i] = min(ans,mem[i-1]+500);
		}else {
			mem[i] = mem[i-1]+500;
		}
	}
	return  mem[num];
}


int main(){
	scanf("%lld",&n);
	printf("%lld",rec(n));
	return 0;
}
