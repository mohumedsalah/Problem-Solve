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
int t, n, xx, yy;
vector<int> arr[50010];
int vis[50010], sum[50010], cnt = 0;
int dfs(int inx) {
	int ret = 0;
	repi(i, 0, sz(arr[inx]))
	{
		if (vis[arr[inx][i]] == -1) {
			vis[arr[inx][i]] = 1;
			ret += 1 + dfs(arr[inx][i]);
			vis[arr[inx][i]] = -1;
		}
	}
	return sum[inx] = ret;
}
int main() {
	rint(t);

	while (t--) {
		memset(vis, -1, sizeof vis);
		memset(sum, 0, sizeof sum);
		rint(n);
		repi(i,1,n+1)
		{
			arr[i].clear();
		}
		repi(i,0,n)
		{
			rint(xx), rint(yy);
			arr[xx].pb(yy);
		}
		int mx = -1, mxinx = 0;
		repi(i,1,n+1)
		{
			vis[i] = 1;
			int r = sum[i] == 0 ?  dfs(i):sum[i];
			vis[i] = -1;
			//cout << r << " ";
			if (r > mx) {
				mx = r;
				mxinx = i;
			}
		}
		printf("Case %d: %d\n", ++cnt, mxinx);
	}

	return 0;
}
