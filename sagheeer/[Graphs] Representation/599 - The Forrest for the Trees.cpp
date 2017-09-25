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
char str[50];
char in[26 * 3];
vector<int> arr[26];
int vis[26];
void dfs(int inx){
	repi(i,0,arr[inx].size())
			if(vis[arr[inx][i]] == -1){
				vis[arr[inx][i]] = 1;
				dfs(arr[inx][i]);
			}
}
int main() {

	int n, cons, tree;
	rint(n);
	repi(i,0,n)
	{
		repi(i,0,26)
				arr[i].clear();
		cons = 0;
		tree = 0;
		memset(vis, 0, sizeof vis);
		while (rs(str) && str[0] != '*') {
			arr[str[1] - 'A'].pb(str[3] - 'A');
			arr[str[3] - 'A'].pb(str[1] - 'A');
			vis[str[1] - 'A'] = vis[str[3] - 'A'] = -1;
		}
		rs(in);
		int strlenn = ssz(in);
		for (int i = 0; i < strlenn; i += 2) {
			if (vis[in[i] - 'A'] == 0)
				cons++;
		}
		for (int i = 0; i < strlenn; i += 2) {
			if (vis[in[i] - 'A'] == -1)
				vis[in[i] - 'A'] = 1,dfs(in[i] - 'A'),tree++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tree,cons);
	}

	return 0;
}
