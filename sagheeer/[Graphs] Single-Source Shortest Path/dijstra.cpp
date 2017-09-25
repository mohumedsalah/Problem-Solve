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
vii arr[100];
int cost[100];
priority_queue<ii, vector<ii>, greater<ii> > pq;
int main() {
	int n, m, xx, yy, zz, source, des;
	rint(n);
	memset(cost, 1, sizeof cost);
	repi(i,0,m)
	{
		rint(xx), rint(yy), rint(zz);
		arr[xx].pb(ii(yy, zz));
		arr[yy].pb(ii(xx, zz));
	}
	rint(source), rint(des);
	pq.push(ii(0, source));
	cost[source] = 0;
	ii cur;
	while (pq.size()) {
		cur = pq.top();
		pq.pop();
		int d = cur.f, u = cur.s;
		if (d > cost[u])
			continue;
		repi(i,0, sz(arr[u]))
		{
			ii ch = arr[u][i];
			int v = ch.f;
			int c = ch.s;
			if (c + d < cost[v]) {
				cost[v] = c + d;
				pq.push(ii(cost[v], v));
			}
		}
	}
	pint(cost[des]);

	return 0;
}
