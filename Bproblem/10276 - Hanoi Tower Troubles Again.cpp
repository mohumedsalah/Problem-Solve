#include <bits/stdc++.h>

using namespace std;
long long arr[55];
int main() {

	int t, n;
	scanf("%d", &t);
	while (t--) {
		memset(arr, -1, sizeof arr);
		scanf("%d", &n);
		int cnt = 1;
		while (true) {
			int f = 0;
			for (int i = 1; i <= n; i++) {
				if (arr[i] == -1)
					continue;
				long long r = arr[i] + cnt;
				long long t = sqrt(r);
				if (t * t == r) {
					f = 1;
					arr[i] = cnt;
					cnt++;
					break;
				}
			}
			if (f)
				continue;
			for (int i = 1; i <= n; i++) {
				if (arr[i] == -1) {
					arr[i] = cnt;
					cnt++;
					f = 1;
					break;
				}
			}
			if (!f)
				break;
		}

		printf("%d\n", cnt-1);
	}

	return 0;
}
