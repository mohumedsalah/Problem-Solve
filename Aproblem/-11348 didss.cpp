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
int vis[10011];
int arr[55][55];
int stmps[55];
double ret[55];
int main() {
	//freopen("in.txt", "r", stdin);
	int t, n, xx;
	int cnt = 0;
	rint(t);
	while (t--) {
		memset(vis, -1, sizeof vis);
		memset(ret, 0, sizeof ret);
		rint(n);
		repi(i,0,n)
		{
			rint(stmps[i]);
			repi(j,0,stmps[i])
			{
				rint(xx);
				if (vis[xx] == -1 || vis[xx] == i)
					vis[xx] = i;
				else
					vis[xx] = -2;
				arr[i][j] = xx;
			}
		}
		int div = 0;
		repi(i,0,10010)
			if (vis[i] != -1 && vis[i] != -2)
				div++;
		//cout << div << endl;
		//int f = 0;
		repi(i,0,n)
		{
			repi(j,0,stmps[i])
			{
				if (vis[arr[i][j]] != -1 && vis[arr[i][j]] != -2) {
					ret[i] += 100 / double(div);
					vis[arr[i][j]] = -2;
				}
			}
		}
		printf("Case %d: ", ++cnt);
		repi(i,0,n)
		{
			pf(ret[i]);
			if (i == n - 1)
				printf("%%");
			else
				printf("%% ");
		}
		pnl();

	}

	return 0;
}
