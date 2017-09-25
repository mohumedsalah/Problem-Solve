#include <bits/stdc++.h>

using namespace std;
class node {
public : int inx,v;
};
bool operator < (node a, node b){
	if(a.v != b.v) return a.v > b.v;
	else return a.inx < b.inx;
}
node make_node(int inx, int v){
	node n;
	n.inx = inx;
	n.v = v;
	return n;
}
priority_queue<node> q;
int vis[20005];
vector<pair<int,int> > arr[20005];
int solve(int s, int t){
	memset(vis, -1 , sizeof vis);
	while(q.size())
		q.pop();
	q.push(make_node(s,0));
	while(!q.empty()){
		node cur = q.top();
		q.pop();
		vis[cur.inx] = 1;
		if(cur.inx == t){
			return cur.v;
		}
		for(int i = 0 ; i < (int)arr[cur.inx].size();i++){
			if(vis[arr[cur.inx][i].first] != -1)continue;
			q.push(make_node(arr[cur.inx][i].first,arr[cur.inx][i].second + cur.v));
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	int cnt = 0;
	while(t--){
		int n , m ,s,tr;
		scanf("%d%d%d%d",&n,&m,&s,&tr);
		for(int i = 0 ;i < m ;i++){
			int xx, yy, zz;
			scanf("%d%d%d",&xx,&yy,&zz);
			arr[xx].push_back(make_pair(yy,zz));
			arr[yy].push_back(make_pair(xx,zz));
		}
		int ret = solve(s,tr);
		if(ret == -1)
			printf("Case #%d: unreachable\n",++cnt);
		else
			printf("Case #%d: %d\n",++cnt,ret);
		for(int i = 0 ; i <= n;i++)
			arr[i].clear();
	}



	return 0;
}
