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
map<string, int> mp1;
int dfsl[11000], dfsn[11000],inst[11000], dfscnt, n, m;
vi arr[11000];
string xx, yy;
int ret;
void tarjan(int inx) {
	inst[inx] = 1;
	dfsn[inx] = dfsl[inx] = dfscnt++;
	repi(i,0,sz(arr[inx]))
	{
		int ch = arr[inx][i];
		if (dfsl[ch] == -1) {
			tarjan(ch);
			dfsl[inx] = min(dfsl[inx], dfsl[ch]);
		} else if(inst[ch]==1)
			dfsl[inx] = min(dfsl[inx], dfsl[ch]);
	}
	if (dfsl[inx] == dfsn[inx])
		ret++;
	inst[inx] = 0;
}
int main() {
	//freopen("in.txt", "r", stdin);
	while (rint(n) && rint(m) && (n || m)) {
		mp1.clear();
		ret = 0;
		dfscnt = 0;
		memset(dfsl, -1, sizeof dfsl);
		memset(dfsn, -1, sizeof dfsn);
		memset(inst, 0, sizeof inst);
		repi(i,0,n)
			arr[i + 1].clear();
		getchar();
		repi(i,0,n)
		{
			getline(cin, xx);
			mp1[xx] = i + 1;
		}
		repi(i,0,m)
		{
			getline(cin, xx);
			getline(cin, yy);
			arr[mp1[xx]].pb(mp1[yy]);
			//cout << mp1[xx] << " " << mp1[yy] <<endl;
		}
		repi(i,0,n)
		{
			if (dfsn[i + 1] == -1)
				dfscnt = 0, tarjan(i + 1);
		}
		pint(ret), pnl();
	}

	return 0;
}
