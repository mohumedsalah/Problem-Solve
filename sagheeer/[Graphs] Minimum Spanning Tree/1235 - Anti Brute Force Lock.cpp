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

int _sc;
int p[550];
//vector<pair<int, ii> > edgelist;
void initSet(int N) {
	repi(i,0, N + 1)
		p[i] = i;
	_sc = N + 1;
}
int findSet(int i) {
	return p[i] == i ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	if (!isSameSet(i, j))
		p[findSet(i)] = findSet(j), _sc--;
}

int finddif(int mm, int ll) {
	if (ll < mm)
		swap(ll, mm);
	return min(ll - mm, 10 - (ll - mm));
}
char in[510][5];
vector<pair<int, ii> > edgelist;
int main() {
	//freopen("in.txt", "r", stdin);
	int t, n;
	rint(t);
	while (t--) {
		edgelist.clear();
		repi(i,0,4)
		{
			in[0][i] = '0';
		}
		rint(n);
		initSet(n);
		repi(i,1,n+1)
		{
			rs(in[i]);
		}
		repi(i,1,n + 1)
		{
			repi(j,1,i)
			{
				int r = 0;
				repi(k,0,4)
				{
					r += finddif(in[j][k] - '0', in[i][k] - '0');
				}
				edgelist.pb(mp(r, ii(j, i)));
			}
		}
		sort(edgelist.begin(), edgelist.end());
		int ret = 0;
		repi(i,0,sz(edgelist))
		{
			int t = _sc;
			unionSet(edgelist[i].s.f, edgelist[i].s.s);
			if (t == _sc)
				continue;
			ret += edgelist[i].f;
		}

		int star = INF;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				int tmp = finddif((in[0][k] - '0' ), (in[i][k] - '0'));
				sum += tmp;
			}
			if (sum < star)
				star = sum;
		}
		pint(ret+star), pnl();

	}

	return 0;
}
