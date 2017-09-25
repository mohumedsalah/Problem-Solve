#include <bits/stdc++.h>

using namespace std;
int arr[105][105];
int dp[105][105];
int main() {
	int n, m, e, t;
	scanf("%d%d%d%d", &n, &e, &t, &m);
	memset(arr, 1, sizeof arr);
	memset(dp,1,sizeof dp);
	for (int i = 0; i < m; i++) {
		int xx, yy, zz;
		scanf("%d%d%d", &xx, &yy, &zz);
		arr[xx][yy] = zz;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = arr[i][j];
			if (i == j) dp[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] < 1e7 && dp[k][j] < 1e7) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	int ret = 0;
	for(int i = 1; i <= n;i++ ){
		if(dp[i][e] <= t )
			ret++;
	}
	printf("%d",ret);

return 0;
}
