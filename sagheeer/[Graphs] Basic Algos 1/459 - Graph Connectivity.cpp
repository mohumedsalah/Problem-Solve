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
int n;
string str;
vector<int> arr[27];
int vis[27];
void dfs(int inx) {
	vis[inx] = 1;
	repi(i,0,sz(arr[inx]))
		if (!vis[arr[inx][i]])
			dfs(arr[inx][i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	scanf("%d\n\n", &t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		repi(i,0,26)
			arr[i].clear();
		string x;
		getline(cin,x);
		int n = x[0] - 'A';
		while (1) {
			if (!getline(cin, str) || str.empty())
				break;
			arr[str[0] - 'A'].pb(str[1] - 'A');
			arr[str[1] - 'A'].pb(str[0] - 'A');
		}
		int ret = 0;
		repi(i,0,n + 1)
		{
			if (vis[i] != 0)
				continue;

			dfs(i);
			ret++;
		}
		pint(ret), pnl();
		if (t != 0)
			pnl();
	}

	return 0;
}
