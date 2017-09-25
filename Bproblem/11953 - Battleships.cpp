#include <bits/stdc++.h>

using namespace std;
int vis[105][105];
char arr[105][105];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n;
bool inBox(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < n;
}
void dfs(int x, int y) {
	if (vis[x][y] != -1 )
		return;
	vis[x][y] = 1;
	for(int i= 0; i < 4;i++){
		int ni =x + dx[i],nj = y + dy[i];
		if(inBox(ni,nj) && vis[ni][nj] == -1 && arr[ni][nj] != '.')
			dfs(ni,nj);
	}
}
int main() {
	//freopen("in.txt","r",stdin);
	int t;
	int cnt = 0;
	scanf("%d",&t);
	while(t--){
		memset(vis, -1 , sizeof vis);
		cnt ++;
		scanf("%d",&n);
		for(int i = 0 ;i < n ;i++){
			scanf("%s",arr[i]);
		}
		int ret = 0;
		for(int i = 0;i <n;i++){
			for(int j= 0; j < n;j++){
				if(arr[i][j] == 'x' && vis[i][j] == -1){
					dfs(i,j);
					ret++;
				}
			}
		}
		printf("Case %d: %d\n",cnt,ret);

	}
	return 0;
}
