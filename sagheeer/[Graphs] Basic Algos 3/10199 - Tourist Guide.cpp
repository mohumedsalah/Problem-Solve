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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
map<string, int> mp;
vi arr[110];
char mpstr[110][50];
char srt[50];
string xx, yy;
int n, m, x, y, dfsn[110], dfsl[110], cntd = 0, cnt = 0, hh[110];
bool root;
void tarjan(int inx, int par) {
	dfsn[inx] = dfsl[inx] = cntd++;
	repi(i,0, sz(arr[inx]))
	{
		int ch = arr[inx][i];
		if (dfsn[ch] == -1) {
			tarjan(ch, inx);
			dfsl[inx] = min(dfsl[ch], dfsl[inx]);
			if (dfsl[ch] >= dfsn[inx]) {
				if (!root && dfsn[inx] == 0) {
					root = true;
				} else {
					hh[inx] = 1;
				}
			}
		} else if (ch != par)
			dfsl[inx] = min(dfsl[inx], dfsn[ch]);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (rint(n) && n) {
		if (cnt != 0)
			pnl();
		cntd = 0;

		root = false;
		mp.clear();
		repi(i,0,n)
			arr[i + 1].clear();
		memset(dfsn, -1, sizeof dfsn);
		memset(dfsl, -1, sizeof dfsl);
		memset(hh, 0, sizeof hh);
		repi(i,0,n)
		{
			rs(mpstr[i + 1]);
			xx = mpstr[i + 1];
			//cout << xx << endl;
			mp[xx] = i + 1;
		}
		rint(m);
		repi(i,0,m)
		{
			rs(srt), xx = srt, x = mp[xx];
			rs(srt), yy = srt, y = mp[yy];
			//cout << xx << yy << endl;
			//cout << x << " " << y << endl;
			arr[x].pb(y);
			arr[y].pb(x);
		}
		repi(i,1,n+1){
			cntd = 0;
			root = false;
			if (dfsn[i] == -1)
				tarjan(i, -1);
		}
		int ans = 0;
		repi(i,0,n)
		{
			if (hh[i])
				ans++;
		}
		printf("City map #%d: %d camera(s) found\n", ++cnt, ans);
		vector<string> ss;
		repi(i,0,n)
		{
			if (hh[i + 1]) {
				ss.pb(mpstr[i + 1]);
			}
		}
		sort(ss.begin(), ss.end());
		repi(i,0,ss.size())
		{
			cout << ss[i] << endl;
		}
		//cout << arr[0] << endl;

	}
	return 0;
}
