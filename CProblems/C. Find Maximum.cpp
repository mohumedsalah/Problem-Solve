#include <bits/stdc++.h>

using namespace std;
#define f first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
int const mx = 1e5 + 6;
int arr[mx];
ll sum[mx];
ll sone[mx];
char s[mx];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d ", &arr[i]);
	scanf("%s", s);
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0')
			sum[i] = arr[i] + sum[i - 1];
		else
			sum[i] = sum[i - 1];
		if (s[i - 1] == '1')
			sone[i] = arr[i] + sone[i - 1];
		else
			sone[i] = sone[i - 1];
	}
	ll ret = 0;
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i - 1] == '1') {
			if (sum[i] <= arr[i]) {
				ret += arr[i];
				continue;
			}
			ans = max(ans, sum[i] + sone[i - 1] + ret);
			ret += arr[i];
		}
	}
	cout << max(ans,ret);

	return 0;
}
