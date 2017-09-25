#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define f first
#define s second
char arr[52][52];
ii p[52][52];
int vis[52][52];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m;
bool inBox(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}
bool solve(int x, int y) {
	if (vis[x][y] != -1) {
		if (p[p[x][y].f][p[x][y].s].f == x && p[p[x][y].f][p[x][y].s].s == y) {
			return 0;
		} else {
			return 1;
		}
	}
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ni = dx[i] + x;
		int nj = dy[i] + y;
		if(inBox(ni,nj) && arr[ni][nj] == arr[x][y]){
			int tx = p[ni][nj].f;
			int ty = p[ni][nj].s;
			p[ni][nj].f =x,p[ni][nj].s = y;
			if(solve(ni,nj)){
				return 1;
			}else{
				p[ni][nj].f = tx;
				p[ni][nj].s = ty;
			}
		}
	}
	return 0;
}
int main() {
	memset(vis, -1, sizeof vis);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 1)
				continue;
			if (solve(i, j)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
