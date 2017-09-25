
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[55][55];
bool che(int r, int c, int v) {
	for (int j = 0; j < n; j++) {
		if (j == c)
			continue;
		int s = arr[r][j];
		for (int i = 0; i < n; i++) {
			if (i == r)
				continue;
			if (s + arr[i][c] == v)
				return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(arr[i][j] == 1)
				continue;
			if(che(i,j,arr[i][j]))
				continue;
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
