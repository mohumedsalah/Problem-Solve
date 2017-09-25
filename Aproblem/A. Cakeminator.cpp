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
char arr[20][20];
int vis[20][20];
int main() {

	int r, c;
	rint(r), rint(c);
	repi(i,0,r)
	{
		rs(arr[i]);
	}
	int ans = 0;
	repi(i,0,r)
	{
		int ret = 0;
		repi(j,0,c)
		{
			if (arr[i][j] == 'S') {
				ret = 0;
				break;
			}
			ret++;
		}
		if (ret != 0)
			repi(j,0,c)
			{
				vis[i][j] = 1;
			}
		ans += ret;

	}
	//pint(ans), pnl();
	repi(i,0,c)
	{
		int ret = 0;
		repi(j,0,r)
		{
			if (arr[j][i] == 'S') {
				ret = 0;
				break;
			}
			if (vis[j][i] == 0) {
				vis[j][i] = 1;
				ret++;
			}
		}
		ans += ret;

	}
	pint(ans);

	return 0;
}
