#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll arr[50001];
int main(){
	//freopen("in.txt","r",stdin);
	arr[0] = 0;
	for(ll i = 1; i <= 50000; i++){
		arr[i] = arr[i - 1] + (i*i*i);
	}
	int t;
	while(cin >> t){
		printf("%lld\n",arr[t]);
	}
	return 0;
}
