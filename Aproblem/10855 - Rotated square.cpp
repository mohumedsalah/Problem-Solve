#include <bits/stdc++.h>

using namespace std;

typedef vector<char> row;
typedef vector<row> matrix;
matrix N;
matrix n;
matrix define(int n) {
	return matrix(n, row(n, ' '));
}
matrix rotate(matrix a) {
	int n = a.size();
	matrix ret = define(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret[j][n - 1 - i] = a[i][j];
		}
	}
	return ret;
}
bool search(int x, int y) {
	for (int xx = 0; xx < n.size(); xx++) {
		int f = 1;
		for (int yy = 0; yy < n.size(); yy++) {
			if (n[xx][yy] != N[xx + x][yy + y]) {
				f = 0;
				break;
			}
		}
		if (!f) {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("in.txt", "r", stdin);
	int a, b;
	string ss;
	while (scanf("%d %d", &a, &b) && a && b) {
		N = define(a);
		n = define(b);
		for (int i = 0; i < a; i++) {

			cin >> ss;
			for (int j = 0; j < a; j++) {
				N[i][j] = ss[j];
			}
		}
		for (int i = 0; i < b; i++) {
			cin >> ss;
			for (int j = 0; j < b; j++) {
				n[i][j] = ss[j];
			}
		}
		for (int k = 0; k < 4; k++) {

			int ret = 0;
			for (int i = 0; i <= a - b; i++) {
				for (int j = 0; j <= a - b; j++) {
					if (search(i, j))
						ret++;
				}
			}
			if (k == 3)
				printf("%d\n", ret);
			else
				printf("%d ", ret);
			n = rotate(n);

		}

	}
	return 0;
}
