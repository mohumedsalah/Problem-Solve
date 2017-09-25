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
ll arr[3][3];
int x[] = { 0, 1, 2 };
char sp[] = { 'B', 'G', 'C' };
char re[3];
int main() {
	ll xx;
	while (cin >> xx) {
		repi(i,0,3)
		{
			repi(j,0,3)
			{
				if (i == 0 && j == 0)
					arr[0][0] = xx;
				else
					rl(arr[i][j]);
			}
		}
		ll ans = INF_LL, ret;
		do {
			ret = 0;
			repi(i,0,3)
			{
				repi(j,0,3)
				{
					if (j == x[i])
						continue;
					ret += arr[i][j];
				}
			}
			if (ret < ans) {
				ans = ret;
				repi(i,0,3)
					re[i] = sp[x[i]];
			}
		} while (next_permutation(x, x + 3));
		repi(i,0,3)
			pc(re[i]);
		psp();
		pl(ans);
		pnl();
	}
	return 0;
}
