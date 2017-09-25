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
int arr[100];
int vis[45][45];
int main() {

	int n, m;
	ll t;
	rint(n), rint(m), rl(t);
	repi(i,0,m)
	{
		rint(arr[i]);
	}
	sort(arr, arr + n);
	int ans = 0;
	repi(i,0,m)
	{
		if (i != 0 && arr[i] == arr[i - 1])
			continue;
		repi(j,0,n)
		{
			if (t - arr[i] > 0) {
				vis[i][j] = 1;
				t -= arr[i];
				ans++;
				if (i == m - 1)
					ans++;
			}
		}
	}
	if (t) {
		repi(i,0,m)
		{
			repi(j,0,n)
			{
				if (!vis[i][j]) {
					if (t - arr[i] > 0) {
						vis[i][j] = 1;
						t -= arr[i];
						ans++;
						if (i == m - 1)
							ans++;
					}
				}
			}
		}
	}
	pint(ans);
	return 0;
}
