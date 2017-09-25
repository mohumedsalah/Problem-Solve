#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
string memo[101][901];
int l, s;
void pr(int s, int e, char p) {
	for (int i = s; i < e; i++)
		printf("%c", p);
}
int main() {
	int l, s;
	scanf("%d %d", &l, &s);
	if (l == 0) {
		puts("-1 -1");
		return 0;
	}
	if (l == 1) {
		if (s <= 9)
			printf("%d %d", s, s);
		else
			puts("-1 -1");
		return 0;
	}
	if (s == 0) {
		if (l == 1)
			puts("0 0");
		else
			puts("-1 -1");
		return 0;
	}
	if (ceil(double(s) / 9) > l) {
		puts("-1 -1");
		return 0;
	}
	int n9 = s / 9;
	int r9 = s % 9;
	int nz;
	if (r9 == 0) {
		nz = l - n9;
		if (nz == 0) {
			for (int i = 0; i < n9; i++) {
				printf("9");
			}
			printf(" ");
		} else {
			printf("1");
			for (int i = 0; i < nz - 1; i++) {
				printf("0");
			}
			printf("8");
			for (int i = 0; i < n9 - 1; i++) {
				printf("9");
			}
			printf(" ");

		}

		for (int i = 0; i < n9; i++)
			printf("9");
		for (int i = 0; i < nz; i++)
			printf("0");

	} else {
		nz = l - n9 - 1;
		if (nz == 0) {
			printf("%d", r9);
			for (int i = 0; i < n9; i++)
				printf("9");

		} else {
			printf("1");
			for (int i = 0; i < nz - 1; i++) {
				printf("0");
			}
			printf("%d", r9 - 1);
			for (int i = 0; i < n9; i++)
				printf("9");
		}

		printf(" ");
		for (int i = 0; i < n9; i++)
			printf("9");
		printf("%d", r9);
		for (int i = 0; i < nz; i++)
			printf("0");

	}

	return 0;
}
