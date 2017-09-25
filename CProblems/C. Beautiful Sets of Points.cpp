#include <bits/stdc++.h>

using namespace std;

int main(){

	int n , m;
	scanf("%d %d",&n,&m);
	int t = min(n, m);
	printf("%d\n",t + 1);
	for(int i = 0 ; i <= t;i++){
		printf("%d %d\n",i , t - i);
	}
	return 0;
}
