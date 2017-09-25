#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pll;
#define f first
#define s second
pll arr[100005];
int n, d;
int main() {
	scanf("%d%d", &n, &d);
	int t = n;
	while (t--) {
		scanf("%d%d", &arr[t].f, &arr[t].s);
	}
	sort(arr, arr + n);
	ll res = 0, curr = 0;
	int last = 0, nxt = 0;s
	sort(arr, arr + n);
	while (nxt < n) {
		while (nxt < n && arr[nxt].f - arr[last].f < d)
			curr += arr[nxt++].s;
		res = max(res, curr);
		curr -= arr[last++].s;
	}
	printf("%I64d", res);
	return 0;
}
