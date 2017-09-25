#include <bits/stdc++.h>
using namespace std;
int n, m ,t,xx;
vector<int> arr[110];
vector<int> lag[110];
int vis[110];
void dfs(int inx){
	if(vis[inx] != -1)
		return;
	vis[inx] = 1;
	for(int i = 0; i < arr[inx].size();i++){
		dfs(arr[inx][i]);
	}
}
int main(){
	int ff = 0;
	memset(vis, -1, sizeof vis);
	scanf("%d %d",&n ,&m);
	for(int i = 1 ; i <= n;i++){
		scanf("%d",&t);
		if(t != 0)
			ff = 1;
		while(t--){
			scanf("%d",&xx);
			lag[xx].push_back(i);
		}
	}
	if(ff == 0){
		printf("%d",n);
		return 0;
	}
	for(int k = 1 ; k <= m ;k++){
		for(int i = 0 ; i < lag[k].size();i++){
			for(int j = i + 1;j < lag[k].size();j++){
				arr[lag[k][i]].push_back(lag[k][j]);
				arr[lag[k][j]].push_back(lag[k][i]);
			}
		}
	}
	int ans = -1;
	for(int i = 1; i <= n;i++){
		if(vis[i] == -1){
			ans++;
			dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
