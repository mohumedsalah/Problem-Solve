#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long long a, b;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld", &a,&b);
		if(a > b)
			puts(">");
		else if(a < b)
			puts("<");
		else
			puts("=");
	}
	return 0;
}
