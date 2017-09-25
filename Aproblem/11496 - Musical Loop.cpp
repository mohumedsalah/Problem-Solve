#include <bits/stdc++.h>

using namespace std;
int const mx = 1e4 + 9;
int arr[mx];
int main() {
	int t;
	while (scanf("%d", &t) && t != 0) {
		for (int i = 1; i <= t; i++) {
			scanf("%d", &arr[i]);
		}
		arr[0] = arr[t];
		arr[t + 1] = arr[1];
		int ret = 0;
		for (int i = 1; i <= t; i++) {
			if ((arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
					|| (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])) {
				ret++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
