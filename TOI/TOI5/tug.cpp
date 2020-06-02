#include <bits/stdc++.h>
using namespace std;
int n,num,ans=0;
vector<int> v1;
vector<int> v2;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
	 	scanf("%d",&num);
		v1.push_back(num);
	}
	for (int i=0;i<n;++i){
		scanf("%d",&num);
		v2.push_back(num);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for (int i=0;i<n;++i){
		if (v1[i] < v2[i]){
			ans += (v2[i]-v1[i]);
		}
		else {
			ans += (v1[i]-v2[i]);
		}
	}
	printf("%d",ans);
	return 0;
}
