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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
int vis[26];
char in[10000];
int t, r, c, n, m, cnt = 0;
int main() {

	//freopen("in.txt", "r", stdin);
	rint(t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		rint(r), rint(c), rint(n), rint(m);
		getchar();
		repi(i,0, r)
		{
			rs(in);
			repi(j,0,c)
			{
				vis[in[j] - 'A']++;
			}
		}
		int mx = 0, mul = 0;
		repi(i,0,26)
		{
			mx = max(vis[i], mx);
		}
		repi(i,0,26)
		{
			if(mx == vis[i]){
				mul++;
			}
		}
		int ans = mx * mul * n + ((r * c) - (mx * mul)) * m;
		printf("Case %d: %d\n", ++cnt, ans);
	}

	return 0;
}
