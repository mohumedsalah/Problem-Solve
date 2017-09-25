#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	//freopen("in.txt","r",stdin);
	ll s , d, xx , yy;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&s,&d);
		double x = (s + d)/2.0;
		double y = s - x;
		if(x < 0 || y < 0 || ceil(x) != floor(x)){
			puts("impossible");
		}else{
			xx = (ll)x;
			yy = (ll)y;
			printf("%lld %lld\n",xx,yy);
		}
	}
	return 0;
}
