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
int mx[1050][1050];
int main() {
	//freopen("in.txt", "r", stdin);
	int T, N, D, xx, yy, zz;
	rint(T);
	while (T--) {
		memset(mx, 0, sizeof mx);
		rint(D);
		rint(N);
		repi(k,0,N)
		{
			rint(xx), rint(yy), rint(zz);
			int r = (xx - D >= 0) ? xx - D : 0;
			int l = xx + D + 1 <= 1035 ? xx + D + 1 : 1035;
			repi(i, r , l)
			{
				int star = (yy - D >= 0) ? yy - D : 0;
				int end = yy + D + 1 <= 1035 ? yy + D + 1 : 1035;
				repi(j,star,end)
				{
					mx[i][j] += zz;
				}
			}

		}
		int x = -1, y = -1;
		int ans = 0;
		for (int i = 0; i < 1030; i++) {
			for (int j = 0; j < 1030; j++) {
				if (ans < mx[i][j]) {
					ans = mx[i][j];
					x = i;
					y = j;
				}
			}
		}
		printf("%d %d %d\n", x, y, ans);
	}

	return 0;
}

