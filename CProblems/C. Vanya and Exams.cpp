#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> ii;
ii arr[100005];
int n;
ll r, avg, summ = 0;

int main() {

	scanf("%d", &n);
	cin >> r >> avg;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].s, &arr[i].f);
		summ += arr[i].s;
	}
	sort(arr, arr + n);
	ll ans = 0;
	ll sum = avg * n;
	if (summ >= sum) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		ll t = summ + (r - arr[i].s);
		if (t < sum) {
			ans += ((r - arr[i].s) * arr[i].f);
			summ = t;
		} else {
			ans += ((sum - summ) * arr[i].f);
			break;
		}
	}
	cout << ans;
	return 0;
}
