#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[2000010];
bool cmp (int a, int b){
	return a > b;
}
int main(){
	ll n;
	cin >> n;
	for(int i = 0 ;i <n;i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n, cmp);
	ll p = 1, ans = 0;
	while(p <= n){
		for(int i = 0 ; i < p;i++){
			ans += (ll)arr[i];
		}
		p *= 4;
	}
	cout << ans << endl;
	return 0;
}
