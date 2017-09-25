#include <bits/stdc++.h>
using namespace std;
int const mx = 1e5 + 10;
char arr[mx];
int x[mx];
int y[mx];
int z[mx];

int main() {
	int r, l;
	scanf("%s", arr);
	int n =(int) strlen(arr);
	for (int i = 1; i <= n; i++) {
		x[i] = x[i - 1], y[i] = y[i - 1], z[i] = z[i - 1];
		if (arr[i - 1] == 'x')
			x[i]++;
		else if (arr[i - 1] == 'y')
			y[i]++;
		else
			z[i]++;
	}
	int q, nx, ny, nz;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &r, &l);
		nx = x[l] - x[r - 1], ny = y[l] - y[r - 1], nz = z[l] - z[r - 1];
		if ((l - r < 2)||(abs(nx - ny) <= 1 && abs(nx - nz) <= 1 && abs(nz - ny) <= 1)) {
			puts("YES");
		} else
			puts("NO");
	}
	return 0;
}
