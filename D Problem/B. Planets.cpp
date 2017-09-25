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
vii arr[100100];
vi blk[100100];
int vis[100100];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int notplk(int inx, int tt) {
	repi(i,0,blk[inx].size())
	{
		if (blk[inx][i] == tt)
			tt++;
		else if (blk[inx][i]>tt) return tt;
	}
	return tt;
}
int main() {
	//freopen("in.txt", "r", stdin);
	memset(vis, -1, sizeof vis);
	int n, m, xx, yy, zz, nm;
	rint(n), rint(m);

	repi(i,0, m)
	{
		rint(xx), rint(yy), rint(zz);
		arr[xx].pb(ii(yy, zz));
		arr[yy].pb(ii(xx, zz));
	}
	repi(inx,1, n + 1)
	{
		rint(nm);
		repi(i,0, nm)
		{
			rint(xx);
			blk[inx].pb(xx);
		}
	}
	int xstr = notplk(1 , 0);
	q.push(mp(xstr, 1));
	vis[1] = 1 ;
	pair<int, int> cur;
	while (q.size()) {
		cur = q.top();
		int xxx = notplk(cur.s, cur.f);
		q.pop();
		vis[cur.s] = 1;
		if (cur.s == n) {
			pint(cur.f);
			return 0;
		}
		repi(i,0, sz(arr[cur.s]))
		{
			if (vis[arr[cur.s][i].f] == -1) {

				q.push(mp(xxx +  arr[cur.s][i].s, arr[cur.s][i].f));
			}
		}
	}
	puts("-1");
	return 0;
}
