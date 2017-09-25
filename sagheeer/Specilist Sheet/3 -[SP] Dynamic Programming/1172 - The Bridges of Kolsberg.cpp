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
int n, m;
string x[1100];
string y[1100];
int xv[1100], yv[1100];
int memo[1100][1100];
int ans = 0;
int solve(int inx, int lOneNotC) {
	int &ret = memo[inx][lOneNotC];
	if (ret != -1)
		return ret;
	if (inx == n || lOneNotC == m)
		return ret = 0;
	repi(i , lOneNotC, m)
	{
		if (x[inx + 1] == y[i]) {
			ret = max(ret, solve(inx + 1, i + 1) + xv[inx + 1] + yv[i]);
		}
		ret = max(ret, solve(inx + 1, i));
	}
	return ret;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t;
	rint(t);
	while (t--) {
		memset(memo, -1, sizeof memo);
		ans = 0;
		rint(n);
		repi(i,0,n)
			cin >> x[i + 1] >> x[i + 1] >> xv[i + 1];
		rint(m);
		repi(i,0,m)
			cin >> y[i] >> y[i] >> yv[i];
		int ret = solve(0, 0);
		pint(ret), psp(), pint(ans), pnl();
	}

	return 0;
}
