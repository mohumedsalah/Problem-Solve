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
int X10[11];
int main() {
	//freopen("in.txt", "r", stdin);
	X10[0] = 1;
	repi(i, 1, 10)
	X10[i] = X10[i - 1] * 10;
	int Case = 0, n;
	char s[100];
	while (scanf("%d", &n) && n >= 0) {
		int p = 0, q = 0;
		rs(s);
		int len = strlen(s) - 1;
		repi(i, 2, len + 1)
		p = p * 10 + (s[i] - 48);
		if (n != 0) {
			p = p - p / X10[n];
			q = X10[len - 1] - X10[len - n - 1];
		} else
			q = X10[len - 1];
		int gcd = __gcd(p, q);
		printf("Case %d: %d/%d\n", ++Case, p / gcd, q / gcd);
	}

	return 0;
}
