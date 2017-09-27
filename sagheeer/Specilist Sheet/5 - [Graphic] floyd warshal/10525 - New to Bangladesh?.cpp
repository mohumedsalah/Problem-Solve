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
ll t[123][123];
ll d[123][123];
int main() {
	//freopen("in.txt", "r", stdin);
	int tt, n, m, xx, yy, st, en;
	ll ti, dist;
	rint(tt);
	while (tt--) {
		rint(n), rint(m);
		memset(t, -1, sizeof t);
		memset(d, -1, sizeof d);
		for(int i = 1; i <= m; i++ ){
		           scanf("%d %d %lld %lld", &xx, &yy, &ti, &dist);
		           if(d[xx][yy] == -1 || t[xx][yy] > ti || (t[xx][yy] == ti && d[xx][yy] > dist)){
		                d[xx][yy] = d[yy][xx] = dist;
		                t[xx][yy] = t[yy][xx] = ti;
		           }
		}
		 for(int i = 1; i <= n; i++ )
		            d[i][i] = t[i][i] = 0;
		repi(k,1, n + 1)
			repi(i,1, n + 1)
				repi(j, 1, n+ 1)
					if (t[i][k] != -1 && t[k][j] != -1) {
						if (t[i][j] == -1 || t[i][k] + t[k][j] <= t[i][j]) {
							if (t[i][k] + t[k][j] == t[i][j]
									&& d[i][k] + d[k][j] < d[i][j]) {
								t[i][j] = t[i][k] + t[k][j];
								d[i][j] = d[i][k] + d[k][j];
							} else if (t[i][k] + t[k][j] != t[i][j]) {
								t[i][j] = t[i][k] + t[k][j];
								d[i][j] = d[i][k] + d[k][j];
							}
						}
					}
		int q;
		rint(q);
		while (q--) {
			rint(xx), rint(yy);
			if (t[xx][yy] == -1) {
				puts("No Path.");
			} else
				printf("Distance and time to reach destination is %lld & %lld.\n",
						d[xx][yy], t[xx][yy]);
		}
		if (tt)
			pnl();
	}

	return 0;
}
