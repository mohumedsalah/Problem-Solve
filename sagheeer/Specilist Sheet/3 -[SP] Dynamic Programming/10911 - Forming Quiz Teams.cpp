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
int x[20], y[20];
double memo[25][1100000];
double solve(int b, int msk) {
	double &ret = memo[b][msk];
	if (ret > -.05)
		return ret;
	int dn;
	setAll(dn,(2*n + 1));
	if(msk == dn)
		return ret = 0.0;
	ret = INF;
	repi(i,1, 2*n + 1)
	{
		if ( !isOn(msk, i)) {
			setBit(msk, i);

			if (b != 0)
				ret = min(ret,
						solve(0 , msk)
								+ hypot(x[b] - x[i], y[b] - y[i]));
			else
				ret = min(ret, solve( i , msk));
			clearBit(msk, i);
		}
	}
	return ret;
}
char chh[250];
int main() {

	//freopen("in.txt","r", stdin);
	int cnt  = 0;
	while (rint(n) && n) {
		repi(i,0,2*n)
			rs(chh),rint(x[i + 1]), rint(y[i + 1]);
		memset(memo, -1 ,sizeof memo);
		double ret = solve(0,1);
		printf("Case %d: %.2lf\n",++cnt, ret);
	}

	return 0;
}
