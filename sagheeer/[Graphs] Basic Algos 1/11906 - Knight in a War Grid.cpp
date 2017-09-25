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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m, incr, incc, q, xx, yy;
int dx[] = { 1, -1, 1, -1 };
int dy[] = { 1, 1, -1, -1 };
int vis[110][110];
int mvis[110][110];
int inBox(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int countway(int i, int j) {
	int ni, nj, ret = 0;
	repi(k,0,4)
	{
		ni = i + (dx[k] * incr), nj = j + (dy[k] * incc);
		if (inBox(ni, nj) && mvis[ni][nj] == 0)
			ret++, mvis[ni][nj] = 1;
	}
	repi(k,0,4)
	{
		ni = i + (dx[k] * incc), nj = j + (dy[k] * incr);
		if (inBox(ni, nj) && mvis[ni][nj] == 0)
			ret++, mvis[ni][nj] = 1;
	}
	repi(k,0,4)
	{
		ni = i + (dx[k] * incr), nj = j + (dy[k] * incc);
		if (inBox(ni, nj) && mvis[ni][nj] == 1)
			mvis[ni][nj] = 0;
	}
	repi(k,0,4)
	{
		ni = i + (dx[k] * incc), nj = j + (dy[k] * incr);
		if (inBox(ni, nj) && mvis[ni][nj] == 1)
			mvis[ni][nj] = 0;
	}
	return ret;
}
pii solve(int i, int j) {
	vis[i][j] = 1;
	int ans = countway(i, j);
	pii ret = pii(0, 0);
	if (ans % 2 == 0)
		ret.f++;
	else
		ret.s++;
	int ni, nj;
	repi(k,0,4)
	{
		ni = i + (dx[k] * incr), nj = j + (dy[k] * incc);
		if (inBox(ni, nj) && vis[ni][nj] == 0) {
			pii ans = solve(ni, nj);
			ret.f += ans.f;
			ret.s += ans.s;
		}
	}
	repi(k,0,4)
	{
		ni = i + (dx[k] * incc), nj = j + (dy[k] * incr);
		if (inBox(ni, nj) && vis[ni][nj] == 0) {
			pii ans = solve(ni, nj);
			ret.f += ans.f;
			ret.s += ans.s;
		}
	}
	return ret;
}
int main() {
	//freopen("in.txt","r",stdin);
	int t,cnt = 0;
	rint(t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(mvis, 0, sizeof mvis);
		rint(n),rint(m), rint(incr), rint(incc);
		rint(q);
		while (q--) {
			rint(xx), rint(yy);
			vis[xx][yy] = -1;
			mvis[xx][yy] = -1;
		}
		pii ans = solve(0,0);
		printf("Case %d: %d %d\n",++cnt,ans.f, ans.s);
	}
	return 0;
}
