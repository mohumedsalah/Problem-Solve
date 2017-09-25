#include <bits/stdc++.h>
using namespace std;
int n, m, xx, yy;
vector<int> g[110];
int vis[110];
vector<int> ans;
vector<int> ret;
bool canColorB(int inx) {
	for (int i = 0; i < (int) g[inx].size(); i++) {
		if (vis[g[inx][i]] == -1)
			return false;
	}
	return 1;
}
void back(int inx) {
	if (inx == n + 1) {
		if (ret.size() > ans.size()) {
			ans.clear();
			for (int i = 0; i < (int) ret.size(); i++)
				ans.push_back(ret[i]);
		}
		return;
	}
	back(inx + 1);
	if (canColorB(inx)) {
		vis[inx] = -1;
		ret.push_back(inx);
		back(inx + 1);
		ret.pop_back();
		vis[inx] = 0;
	}

}
int main() {
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		ret.clear();
		ans.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &xx, &yy);
			g[xx].push_back(yy);
			g[yy].push_back(xx);
		}
		back(1);
		int sz = ans.size();
		printf("%d\n", sz);
		for (int i = 0; i < sz; i++)
			if (i != sz - 1)
				printf("%d ", ans[i]);
			else
				printf("%d\n", ans[i]);

	}
	return 0;
}
