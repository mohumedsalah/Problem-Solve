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
int n, q;
ll arr[50100], xx;
int main() {
	//freopen("in.txt","r",stdin);
	rint(n);
	repi(i,0,n)
	{
		rl(arr[i]);
	}
	sort(arr, arr + n);
	rint(q);
	while (q--) {
		rl(xx);
		int r = 0, l = n;
		ll ans = -1;
		while (r - 1 < l) {
			int m = (r + l) / 2;
			if (arr[m] < xx) {
				ans = max(ans, arr[m]);
				r = m + 1;
			} else {
				l = m - 1;
			}
		}
		if (ans == -1)
			printf("X");
		else
			pl(ans);
		psp();
		r = 0, l = n;
		ans = INF_LL;
		while (r - 1 < l) {
			int m = (r + l) / 2;
			if (arr[m] > xx) {
				ans = min(ans, arr[m]);
				l = m - 1;
			} else {
				r = m + 1;
			}
		}
		if (ans == INF_LL)
			printf("X");
		else
			pl(ans);
		pnl();
	}
	return 0;
}
