#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int const mx = 1e5 + 9;
int arr[mx];
int n, k;
ll sum(int f, int t) {
	return ll(t) * (t - 1) / 2ll - ll(f) * (f + 1) / 2ll;
}
ll binary_search(int inx) {
	if (inx + 2 > n)
		return 0;
	int s = inx + 2, e = n, ss = -1;
	while (s - 1 < e) {
		int m = (s + e) / 2;
		if (abs(arr[m] - arr[inx]) <= k) {
			s = m + 1;
			ss = m;
		} else
			e = m - 1;
	}
	if (ss == -1)
		return 0;
	ll t =  ll(ss) - inx - 2ll  + 1ll;
	return t * (t + 1) / 2ll;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ll ret = 0;
	for (int i = 1; i <= n; i++)
		ret += binary_search(i);
	printf("%I64d", ret);

	return 0;
}
