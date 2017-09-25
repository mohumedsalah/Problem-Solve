#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%lld",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%.6lf", x)
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
#define f first
#define s second
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 2000000000000000000LL
#define INF 1000000000
#define EPS 1e-8
#define mod 1000000007
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
vii arr[110];
int n, m, xx, yy, zz;
int vis[110];
int mx = 0;
void dfs(int inx, int mz) {
	if (inx == yy) {
		mx = max(mx, mz);
		return;
	}
	repi(i,0, sz(arr[inx]))
	{
		int ch = arr[inx][i].f;
		if(arr[inx][i].s < mx)
			return;
		if (vis[ch] == 0) {
			vis[ch] = 1;
			dfs(ch, min(mz, arr[inx][i].s));
			vis[ch]  = 0;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int cnt = 0;
	while (rint(n), rint(m) && (n || m)) {
		repi(i,0,n+1)
			arr[i].clear();
		memset(vis, 0, sizeof vis);
		mx = 0;
		repi(i,0,m)
		{
			rint(xx), rint(yy), rint(zz);
			arr[xx].pb(ii(yy, zz));
			arr[yy].pb(ii(xx, zz));
		}
		rint(xx), rint(yy), rint(zz);
		dfs(xx,INF);
		int ret = (zz + mx - 2) / (mx - 1);
		printf("Scenario #%d\n", ++cnt);
		printf("Minimum Number of Trips = "), pint(ret), pnl(), pnl();
	}
	return 0;
}
