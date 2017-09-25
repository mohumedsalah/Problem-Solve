#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> xx;
vector<ll> cc;
ll POW(ll x, ll y) {
	if (y == 0)
		return 1;
	if (y & 1)
		return x * POW(x * x, y / 2);
	return POW(x * x, y / 2);
}
int main() {
	//freopen("in.txt","r",stdin);
	string s;
	ll a;
	while (getline(cin, s)) {
		xx.clear();
		cc.clear();
		stringstream sin(s);
		while (sin >> a)
			cc.push_back(a);
		reverse(cc.begin(), cc.end());
		getline(cin, s);
		stringstream sin1(s);
		while (sin1 >> a)
			xx.push_back(a);
		for (int i = 0; i < xx.size(); i++) {
			ll cur = xx[i];
			ll ans = 0;
			for (int j = 0; j < cc.size(); j++) {
				ans += POW(cur, j) * cc[j];
			}

			if(i == xx.size() - 1)
				printf("%lld\n", ans);
			else
				printf("%lld ", ans);
		}
	}
	return 0;
}
