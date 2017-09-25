#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
ll POW(ll x, ll y) {
	if (y == 0)
		return 1;
	ll r = (x%m * x%m)%m;
	if (y & 1)
		return (x%m * POW(r, y / 2)) % m;
	return POW(r, y / 2);
}
int main() {
	int n;
	cin >> n >> m;
	long long r = POW(3, n);
	if(r == 0)
		cout << m - 1 << endl;
	else
		cout << r - 1 << endl;
	return 0;
}
