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
int n, m, q, xx, yy;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char arr[1010][1010];
int memo[1010][1010];
int vis[1010][1010];
bool valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] != '*');
}
int solve(int x, int y) {
	if(vis[x][y] != -1)
		return 0;
	vis[x][y] = 1;
	int ret = 0;
	int tt = 0;
	repi(i,0,4)
	{
		int ni = x + dx[i], nj = y + dy[i];
		if (arr[ni][nj] == '*') {
			tt++;
			continue;
		}
		if (valid(ni, nj)) {
			tt += solve(ni, nj);
		}
	}
	ret = tt;
	return ret;
}
void dfsu(int x, int y, int ss) {
	if(memo[x][y] != -1)
		return;
	memo[x][y] = ss;
	repi(i,0,4){
		int ni = x + dx[i], nj = y + dy[i];
		if (valid(ni, nj))
			dfsu(ni, nj, ss);
	}
}
int main() {

	rint(n), rint(m), rint(q);
	getchar();
	memset(memo, -1, sizeof memo);
	memset(vis, -1, sizeof vis);
	repi(i,0,n)
	{
		rs(arr[i]);
	}
	while (q--) {
		rint(xx), rint(yy);
		int ret;
		if(memo[xx-1][yy-1] != -1){
			ret = memo[xx-1][yy-1];
		}
		else{
			ret = solve(xx - 1, yy - 1);
			dfsu(xx - 1, yy - 1, ret);
		}
		pint(ret), pnl();
	}
	return 0;
}
