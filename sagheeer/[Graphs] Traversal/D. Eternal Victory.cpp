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
vector<pii> arr[100010];
int vis[100010];
int n, xx, yy, zz;
ll solve(int inx) {
	ll ret = 0;
	vis[inx] = 1;
	repi(i,0,sz(arr[inx]))
	{
		if (vis[arr[inx][i].f] == 0) {
			ret =  max(ret,ll(arr[inx][i].s)+solve(arr[inx][i].f));
		}
	}
	return ret;
}
int main() {

	rint(n);
	ll ret = 0;
	repi(i,0,n-1)
	{
		rint(xx), rint(yy), rint(zz);
		arr[xx].pb(pii(yy, zz));
		arr[yy].pb(pii(xx, zz));
		ret += 2*zz;
	}
	pl(ret - solve(1));

	return 0;
}
