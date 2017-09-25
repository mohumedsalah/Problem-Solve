#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define f first
#define s second
int vis[110][110];
int n, m, q, xx, yy, cc;
vector<ii> arr[105];
int des;
int solve(int inx, int cl) {
	vis[inx][cl] = 1;
	if (inx == des)
		return 1;
	int ret = 0;
	for (int i = 0; i < (int)arr[inx].size(); i++) {
		if (vis[arr[inx][i].f][arr[inx][i].s] == -1 && (arr[inx][i].s == cl|| cl == -1))
			ret += solve(arr[inx][i].f, arr[inx][i].s);
	}
	return ret;
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> xx >> yy >> cc;
		arr[xx].push_back(ii(yy, cc));
		arr[yy].push_back(ii(xx, cc));
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		memset(vis, -1, sizeof vis);
		cin >> xx >> yy;
		des = yy;
		cout << solve(xx, -1) << endl;
	}
	return 0;
}
