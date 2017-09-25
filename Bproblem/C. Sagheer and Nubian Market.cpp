#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
ll S;
int n;
ll arr[100005];
ll ret[100005];
ll solve(ll m) {
	//memset(ret, -1,sizeof ret);
	ll cost = 0;
	for(int i = 1 ; i <= n;i++){
		ret[i] = arr[i] + (i*m);
	}
	sort(ret, ret+n+1);
	for(int i = 1; i <= m;i++){
		cost += ret[i];
		if(cost > S)
			return -1;
	}
	return cost;
}
int main() {

	cin >> n >> S;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	ll s = 1, e = n, ret = 0;
	while (s <= e) {
		int m = (s + e) / 2;
		ll temp1 = solve(m);
		if (temp1 != -1) {
			ans = temp1;
			ret = m;
			s = m + 1;

		} else {
			e = m - 1;
		}
	}
	cout << ret << " " << ans << endl;
	return 0;
}
