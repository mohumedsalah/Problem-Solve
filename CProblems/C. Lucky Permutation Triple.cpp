#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", i);
	printf("\n");
	for (int i = n - 1; i >= 0; i--)
		if (i % 2 == 0)
			printf("%d ", i);
	for (int i = n - 1; i >= 0; i--)
		if (i % 2 != 0)
			printf("%d ", i);
	printf("\n");
	for (int i = n - 1; i >= 0; i--)
			printf("%d ", i);
	return 0;
}
