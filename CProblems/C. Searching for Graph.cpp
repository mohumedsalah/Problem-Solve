#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, xx, yy;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &xx, &yy);
		int mx = 2 * xx + yy;
		int cnt = 0;
		for (int i = 1; i <= xx; i++) {
			for (int j = i + 1; j <= xx; j++) {
				printf("%d %d\n", i, j);
				cnt++;
				if (cnt == mx)
					goto v;
			}
		}
		v: ;
	}

	return 0;
}
