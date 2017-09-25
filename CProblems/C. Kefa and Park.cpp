#include <bits/stdc++.h>

using namespace std;
int const mx = 1e5 + 6;
vector<int> arr[mx];
int f[mx];
int vis[mx];
int n, m;
int dfs(int inx, int sum){
	if(vis[inx])
		return 0;
	vis[inx] = 1;

	if(arr[inx].size() == 1 && vis[arr[inx][0]]){
		if(sum   <= m)
			return 1;
		else
			return 0;
	}
	if(sum > m)
			return 0;
	int ret = 0;
	for(int i = 0 ;i < (int)arr[inx].size();i++){
		if(f[arr[inx][i]] == 0){
			ret += dfs(arr[inx][i], 0);
		}else{
			ret += dfs(arr[inx][i], sum + 1);
		}
	}
	return ret;

}
int main() {
	memset(vis, 0 , sizeof vis);
	int x, y;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d",&x,&y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	int ret =f[1]? dfs(1,1):dfs(1,0);
	printf("%d",ret);
	return 0;
}
