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
vector<int> arr[110];
vector<pair<pii, int> > vv;
map<pair<pii, int>, int> mapp;
map<pair<pii, int>, int>::iterator it;
int vis[110];
void solve(int inx, int binx, int bbinx) {
	vis[inx] = 1;
	repi(i,0,sz(arr[inx]))
	{
		if (arr[inx][i] == bbinx) {
			it = mapp.find(mp(pii(bbinx, binx), inx));
			if (it == mapp.end()) {
				mapp[mp(pii(bbinx, binx), inx)]++;
				mapp[mp(pii(binx, inx), bbinx)]++;
				mapp[mp(pii(inx, bbinx), binx)]++;

				if (bbinx < binx && binx < inx) {
					vv.pb(mp(pii(bbinx, binx), inx));
				} else if (binx < inx && inx < bbinx) {
					vv.pb(mp(pii(binx, inx), bbinx));
				} else if (inx < bbinx && bbinx < binx) {
					vv.pb(mp(pii(inx, bbinx), binx));
				} else if (bbinx > binx && binx > inx) {
					vv.pb(mp(pii(bbinx, binx), inx));
				} else if (binx > inx && inx > bbinx) {
					vv.pb(mp(pii(binx, inx), bbinx));
				} else if (inx > bbinx && bbinx > binx) {
					vv.pb(mp(pii(inx, bbinx), binx));
				}

			}
		}
		if (vis[arr[inx][i]] == 0 && bbinx == -1) {
			solve(arr[inx][i], inx, binx);
		}
	}
	vis[inx] = 0;
}
int main() {
	//freopen("in.txt","r",stdin);
	int n, xx;
	while (cin >> n) {
		vv.clear();
		mapp.clear();
		repi(i,1,n+1)
			arr[i].clear();
		memset(vis, 0, sizeof vis);
		repi(i,0,n)
		{
			repi(j,0,n)
			{
				rint(xx);
				if (xx == 0)
					continue;
				arr[i + 1].pb(j + 1);
			}
		}
		repi(i,1,n+1)
		{
			solve(i, -1, -1);
		}
		sort(vv.begin(), vv.end());
		repi(i,0,sz(vv))
		{
			printf("%d %d %d\n", vv[i].f.f, vv[i].f.s, vv[i].s);
		}
		printf("total:%d\n\n", sz(vv));

	}

	return 0;
}
