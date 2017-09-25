#include <bits/stdc++.h>

using namespace std;
int memo[110][50005];
int arr[110];
int n;
int dp(int inx, int dif) {
	int &ret = memo[inx][dif];
	if (ret != -1) {
		return ret;
	}
	if (inx == n + 1) {
		return ret = dif;
	}
	ret = min(dp(inx + 1, abs(dif - arr[inx])),
			dp(inx + 1, abs(dif + arr[inx])));
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i + 1]);
		}
		int ret = dp(0, 0);
		printf("%d\n", ret);
	}
	return 0;
}
