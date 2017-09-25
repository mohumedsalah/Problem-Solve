#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define f first
#define s second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n , m , k, xx , yy;
queue<ii>  q;
int vis[2010][2010];
bool inBox(int i , int j){
	return i > 0 && j > 0 && i <= n && j <= m;
}
int main(){
	memset(vis, -1, sizeof vis);
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i < k ;i++ ){
		scanf("%d %d",&xx,&yy);
		q.push(ii(xx,yy));
		vis[xx][yy] = 1;
	}
	ii cur;
	while(q.size()){
		cur = q.front();
		q.pop();
		for(int i = 0 ; i < 4;i++){
			int ni = cur.f + dx[i], nj = cur.s + dy[i];
			if(inBox(ni,nj)&&vis[ni][nj] == -1 ){
				q.push(ii(ni,nj));
				vis[ni][nj] = 1;
			}
		}
	}
	printf("%d %d", cur.f, cur.s);

	return 0;
}
