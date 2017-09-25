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
int vis[110];
vector<int> vv;
vector<int> arr[110];
void dfs(int inx) {
	repi(i,0,sz(arr[inx]))
		if (vis[arr[inx][i]] == -1)
			vis[arr[inx][i]] = 1, dfs(arr[inx][i]);
}
int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, xx, yy;
	while (rint(n) && n) {
		repi(i,1,n + 1){
			arr[i].clear();
		}
		while (rint(xx) && xx) {
			while (rint(yy) && yy) {
				arr[xx].pb(yy);
			}
		}
		int q;
		rint(q);
		while (q--) {
			vv.clear();
			memset(vis, -1, sizeof vis);
			rint(xx);
			dfs(xx);
			repi(i,1,n + 1)
			{
				if (vis[i] == -1)
					vv.pb(i);
			}
			int tt = sz(vv);
			pint(tt);
			if(tt != 0)
				psp();
			repi(i,0,tt)
			{
				pint(vv[i]);
				if (i == tt - 1)
					pnl();
				else
					psp();
			}
			if(tt == 0)
				pnl();
		}
	}
	return 0;
}
