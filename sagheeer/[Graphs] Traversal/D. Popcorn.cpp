#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> ii;
int arr[100005];
int vis[100005];
int ret[100005];
queue<ii> q;
int t,ninx;
int main() {
	freopen("jumping.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(ret, -1, sizeof ret);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		vis[n] = 1;
		q.push(ii(n, 0));
		while (q.size()) {
			ii cur = q.front();
			q.pop();
			ret[cur.f] = cur.s;
			 ninx = cur.f + arr[cur.f];
			if (ninx > 0 && ninx <= n && vis[ninx] == 0)
				q.push(ii(ninx, cur.s + 1)), vis[ninx] = 1;
			ninx = cur.f - arr[cur.f];
			if (ninx > 0 && ninx <= n && vis[ninx] == 0)
				q.push(ii(ninx, cur.s + 1)), vis[ninx] = 1;

		}
		for (int i = 1; i <= n; i++) {
			printf("%d\n", ret[i]);
		}
	}
	return 0;
}
