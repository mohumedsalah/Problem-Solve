#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define f first
#define s second
struct node {
	int c;
	int v;
	int inx;
};
node iii(int c, int v, int inx) {
	node n;
	n.v = v;
	n.c = c;
	n.inx = inx;
	return n;
}
bool cmp(node a, node b) {
	if (a.v == b.v)
		return a.c < b.c;
	return a.v > b.v;
}
node arr[1010];
int vis[1010];
vector<ii> pret;
ii t[1010];
int main() {
	int n, xx, yy, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &xx, &yy);
		arr[i] = iii(xx, yy, i + 1);
	}
	sort(arr, arr + n, cmp);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &xx);
		t[i] = ii(xx, i+1);
	}
	sort(t, t + m);
	int cnt = 0, ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[j].f >= arr[i].c &&vis[t[j].s] == 0) {
				cnt++;
				ret += arr[i].v;
				pret.push_back(ii(arr[i].inx,t[j].s));
				vis[t[j].s] = 1;
				break;
			}
		}
	}
	printf("%d %d\n",cnt, ret);
	for(int i= 0 ; i < cnt;i++){
		printf("%d %d\n",pret[i].f, pret[i].s);
	}
	return 0;
}
