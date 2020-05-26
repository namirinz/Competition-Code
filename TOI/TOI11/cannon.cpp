/*
	Time Complexity : O(K*M*2logN)
	// K <= 400, M <= 1,000, N <= 1,000,000
 
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,k,l;
int place,ans,_maxo,_min,_max;

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&l);
    vector<int> cannon(n);
    for (int i=0;i<n;i++){
        scanf("%d",&cannon[i]);
    }
    for (int i=0;i<k;i++){
        ans = 0;
		_maxo = -1;
        for (int j=0;j<m;j++){
			scanf("%d",&place);
	 	    _min = max(place-l,_maxo+1);
	    	_max = place+l;
	    	_maxo = _max;
		    
			auto l1 = distance(cannon.begin(),lower_bound(cannon.begin(),cannon.end(),_min));
	    	auto l2 = distance(cannon.begin(),upper_bound(cannon.begin(),cannon.end(),_max));
		//cout << l1 << ' ' << l2 << '\n';	
		ans += (l2-l1);
       }
	   printf("%d\n",ans);
			
    }
	
}
