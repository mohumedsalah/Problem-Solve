#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%I64d",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%I64d", x)
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
int arr[15][110][110];
int main() {
	int n, Q, c, xx, yy, zz;
	rint(n), rint(Q), rint(c);
	memset(arr, -1, sizeof arr);
	repi(i,0,n)
	{
		rint(xx), rint(yy), rint(zz);
		arr[0][xx][yy] = zz;
	}
	repi(l,1,c + 1)
	{
		repi(i,0,105)
		{
			repi(j,0,105)
			{
				if (arr[l - 1][i][j] != -1)
					arr[l][i][j] =
							(arr[l - 1][i][j] + 1 > c) ?
									0 : arr[l - 1][i][j] + 1;
			}
		}
	}

	repi(l,0,c + 1)
	{
		repi(i,0,105)
		{
			repi(j,0,105)
			{
				if (arr[l][i][j] == -1)
					arr[l][i][j] = 0;
				if (j > 0)
					arr[l][i][j] += arr[l][i][j - 1];
				if (i > 0)
					arr[l][i][j] += arr[l][i - 1][j];
				if (j > 0 && i > 0)
					arr[l][i][j] -= arr[l][i - 1][j - 1];
			}
		}
	}
	ll t;
	int x1, y1, x2, y2, ret ;
	while (Q--) {
		rl(t);
		int acc = t % (ll(c) + 1ll);
		rint(x1), rint(y1), rint(x2), rint(y2);

		ret = arr[acc][x2][y2] ;
		if (x1 > 0)
			ret -= arr[acc][x1 - 1][y2];
		if (y1 > 0)
			ret -= arr[acc][x2][y1 - 1];
		if (x1 > 0 && y1 > 0)
			ret += arr[acc][x1 - 1][y1 - 1];
		pint(ret), pnl();

	}

	return 0;
}
