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
vector<int> ss;
vector<int> cc[20];
int n, m, xx;
int main() {

	while (cin >> m) {
		ss.clear();
		repi(i,0,5)
		{
			cc[i].clear();
		}
		rint(n);
		repi(i,0,n)
		{
			rint(xx);
			ss.pb(xx);
		}
		if (n > m) {
			repi(i,n,2*m )
			{
				ss.pb(0);
			}
			sort(ss.begin(), ss.end());
			int r = 0, l = sz(ss) - 1;
			int cnt = 0;
			while (r - 1 < l) {
				cc[cnt].pb(ss[r]);
				cc[cnt].pb(ss[l]);
				cnt++;
				r++, l--;
			}
			repi(i,0,m)
			{
				printf("%d: ", i);
				repi(j,0,sz(cc[i]))
				{
					if (!cc[i][j])
						continue;
					pint(cc[i][j]), psp();
				}
				pnl();
			}
		} else {
			repi(i,0,m)
			{
				if (i >= n)
					printf("%d: \n", i);
				 else
					printf("%d: %d\n", i, ss[i]);

			}
		}
		pnl();

	}

	return 0;
}
