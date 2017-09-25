#include <bits/stdc++.h>

using namespace std;
int n, m, xx, yy;
vector<int> arr[100];
int vis[100];
long long dfs(int inx) {
	vis[inx] = 1;
	long long ret = 1 ;
	for (int i = 0; i < (int) arr[inx].size(); i++) {
		if (vis[arr[inx][i]] == -1)
			ret *= (2 * dfs(arr[inx][i]));
	}
	return ret;
}

int main() {
	memset(vis, -1, sizeof vis);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> xx >> yy;
		arr[xx].push_back(yy);
		arr[yy].push_back(xx);
	}
	long long ret = 1;
	for (int i = 1; i <= n; i++) {
		if(vis[i] == -1)
			ret *= dfs(i);
	}
	cout << ret << endl;
	return 0;
}
