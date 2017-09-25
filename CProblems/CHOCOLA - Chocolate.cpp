#include <bits/stdc++.h>

using namespace std;
typedef pair<int, bool> ib;
#define f first
#define s second
ib arr[20001];
int n, m, xx, ret, nr, nc;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		nr = 1, nc = 1;
		scanf("%d %d", &n, &m);
		n--, m--;
		for (int i = 0; i < n; i++) {
			scanf("%d", &xx);
			arr[i] = ib(xx, 0);
		}
		for (int i = n; i < n + m; i++) {
			scanf("%d", &xx);
			arr[i] = ib(xx, 1);
		}
		sort(arr, arr + n + m);
		ret = 0;
		for (int i = n + m - 1; i >= 0; i--) {
			if (arr[i].s == 1) {
				nc++;
				ret += (arr[i].f * nr);
			} else {
				nr++;
				ret += (arr[i].f * nc);
			}
		}
		printf("%d\n", ret);

	}
	return 0;
}
