#include <bits/stdc++.h>

using namespace std;
vector<int> v[2002];
int p[2002];
int vis[2002];
int dfs(int inx) {
	return p[inx] == -1?inx:dfs(p[inx]);
}
int lev(int inx){
	vis[inx] = 1;
	int ret = 0;
	for(int i = 0 ;i < v[inx].size();i++){
		ret = max(ret,1 + lev(v[inx][i]));
	}
	return ret;
}

int main() {
	memset(vis, -1, sizeof vis);
	int n, xx;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> xx;
		p[i] = xx;
		if(xx != -1)
			v[xx].push_back(i);
	}
	int ret = 0;
	for(int i = 1 ; i <= n;i++){
		if(vis[i] == -1){
			int root = dfs(i);
			ret =max(ret, 1 +lev(root));
		}
	}
	cout << ret<< endl;
	return 0;
}
