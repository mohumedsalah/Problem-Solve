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
int arr[1010];
int n, c;
bool che(int x) {
	int nc = 0;
	int curc = x;
	int i = 0;
	while(true)
	{
		while (i < n && curc - arr[i] >= 0) {
			curc -= arr[i];
			i++;
		}
		curc = x;
		nc++;
		if (nc > c)
			return false;
		if (i == n)
			return true;
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> n) {
		rint(c);
		repi(i, 0, n)
			rint(arr[i]);
		int lo = 0, hi = 1e9, ans = -1;
		while (lo - 1 < hi) {
			int m = (hi + lo) / 2;
			if (che(m)) {
				ans = m;
				hi = m - 1;
			} else {
				lo = m + 1;
			}
		}
		pint(ans), pnl();
	}
	return 0;
}
