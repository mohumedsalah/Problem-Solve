#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr;
long long Pow(long long x, long long y) {
	if (y == 0)
		return 1;
	if (y & 1)
		return x * Pow(x * x, y / 2);
	else
		return Pow(x * x, y / 2);
}
int main() {
	//freopen("in.txt","r",stdin);
	int a;
	ll xx, ans;
	string s;
	while (cin >> a) {
		arr.clear();
		getchar();
		getline(cin, s);
		stringstream aa(s);
		while (aa >> xx) {
			arr.push_back(xx);
		}
		ans = 0;
		int cnt = 0;
		for (int i = arr.size() - 2; i >= 0; i--) {
			ans += (cnt + 1) * Pow((ll) a, cnt) * arr[i];
			cnt++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
