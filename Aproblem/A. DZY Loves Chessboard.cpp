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
int vis[110][110];
char arr[110][110];
int ret[110][110];
int n, m;
bool inBox(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void dfs(int i, int j, int ch) {
	if (arr[i][j] == '-') {
		vis[i][j] = 2;
		return;
	}
	vis[i][j] = ch;
	repi(x,0,4)
	{
		int ni = i + dx[x], nj = j + dy[x];
		if (inBox(ni, nj) && vis[ni][nj] == -1)
			dfs(ni, nj, !ch);
	}
}
int main() {

	memset(vis, -1, sizeof  vis);
	rint(n), rint(m);
	getchar();
	repi(i,0,n)
	{
		rs(arr[i]);
	}
	repi(i,0,n)
	{
		repi(j,0,m)
			if (vis[i][j] == -1) {
				dfs(i, j, 0);
			}
	}
	repi(i,0,n)
	{
		repi(j,0,m)
		{
			if (vis[i][j] == 2)
				pc('-');
			else if (vis[i][j] == 0)
				pc('B');
			else
				pc('W');
		}
		pnl();
	}

	return 0;
}
