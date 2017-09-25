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
vector<ii> vv;
vi arr[110];
int dfsn[110], dfsl[110], n, from, to, dfscnt,m,xx,yy;
string str;
int ciri[110];
set<int> qq;
void torjan(int inx, int par) {
	dfsn[inx] = dfsl[inx] = dfscnt++;
	repi(i, 0, sz(arr[inx]))
	{
		int ch = arr[inx][i];
		if (dfsn[ch] == -1) {
			torjan(ch, inx);
			dfsl[inx] = min(dfsl[inx], dfsl[ch]);
			if(dfsl[ch] > dfsn[inx])
				vv.pb(ii(inx,ch));
		} else if (ch != par ){
			dfsl[inx] = min(dfsl[inx], dfsn[ch]);
		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> n && n) {
		qq.clear();
		repi(i,1,n+1)
			arr[i].clear();
		vv.clear();
		dfscnt = 0;
		memset(dfsn, -1, sizeof dfsn);
		memset(dfsl, -1, sizeof dfsl);
		//memset(instack, 0, sizeof instack);
		memset(ciri, 0, sizeof ciri);
		cin >> m;
		repi(i,0,m){
			rint(xx), rint(yy);
			arr[xx].pb(yy);
			arr[yy].pb(xx);
		}

		torjan(1, -1);
		//sort(vv.begin(),vv.end());
		pint(sz(vv)),pnl(),pnl();
		repi(i,0,sz(vv)){
			pint(vv[i].f),psp(),pint(vv[i].s),pnl();
		}
		puts("#");

	}

	return 0;
}
