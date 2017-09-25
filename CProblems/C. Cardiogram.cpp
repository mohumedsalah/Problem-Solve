#include <bits/stdc++.h>

using namespace std;
int arr[1100];
int arrp[5000][5000];
int main() {
	//memset(arrp, -1, sizeof arrp);
	int n, xx;
	cin >> n;
	int sinx = -1, mxx = -1, nr = 0, nc = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &xx);
		nc += xx;
		xx--;
		arr[i] = xx;
		if (xx > mxx) {
			sinx = i;
			mxx = xx;
		}
	}

	int st = 0;
	nr = mxx;
	for (int i = 0; i <= nr; i++)
		for (int j = 0; j <= nc; j++)
			arrp[i][j] = ' ';
	if (sinx % 2 == 0) {
		int f = 1;
		for (int i = sinx - 1; i >= 1; i--) {
			if (f) {
				st += arr[i];
				f = 0;
			} else {
				st -= arr[i];
				f = 1;
			}
		}
	} else {
		int f = 1;
		for (int i = sinx; i >= 1; i--) {
			if (f) {
				st += arr[i];
				f = 0;
			} else {
				st -= arr[i];
				f = 1;
			}
		}
	}

	int b = 0;
	if (sinx == 1) {
		st = arr[1];
	}
	//cout << st << endl;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			int j;
			for (j = 0; j <= arr[i]; j++) {
				arrp[st--][j + b] = '/';
			}
			b += j;
			st++;
		} else {
			int j;
			for (j = 0; j <= arr[i]; j++) {
				arrp[st++][j + b] = 92;
			}
			b += j;
			st--;
		}
	}
	for (int i = 0; i <= nr; i++) {
		for (int j = 0; j < nc; j++)
			printf("%c", arrp[i][j]);
		if (i != nr)
			printf("\n");
	}

	return 0;
}

/*8
 1 2 5 4 1 2 3 1*/
