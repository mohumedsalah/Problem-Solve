#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define x first
#define h second
pll arr[100005];
int n;
int dp[100005][2];
int solve(int inx, int f) {
	int &ret = dp[inx][f];
	if (ret != -1)
		return ret;
	if (inx == n)
		return 1;
	ll fr = arr[inx].x + arr[inx].h;
	ll fl = arr[inx].x - arr[inx].h;
	if (f) {
		if (fr >= arr[inx + 1].x && fl <= arr[inx - 1].x + arr[inx - 1].h)
			return ret = solve(inx + 1, 0);
		if (fr < arr[inx + 1].x)
			ret = max(ret, 1 + solve(inx + 1, 1));
		if (fl > arr[inx - 1].x + arr[inx - 1].h)
			ret = max(ret, 1 + solve(inx + 1, 0));
	} else {
		if (fr >= arr[inx + 1].x && fl <= arr[inx - 1].x)
			return ret = solve(inx + 1, 0);
		if (fr < arr[inx + 1].x)
			ret = max(ret, 1 + solve(inx + 1, 1));
		if (fl > arr[inx - 1].x)
			ret = max(ret, 1 + solve(inx + 1, 0));
	}
	return ret;

}
int main() {
	memset(dp, -1, sizeof dp);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].x >> arr[i].h;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	sort(arr, arr + 1 + n);
	int ans = 1 + solve(2, 0);
	cout << ans << endl;

	return 0;
}
