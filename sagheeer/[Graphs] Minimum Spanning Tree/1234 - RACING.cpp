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
int p[200010];
vector<pair<int, ii> > edgelist;
void initSet(int N) {
	repi(i,0, N + 1)
		p[i] = i;
	_sc = N ;
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
int n, m , xx,yy,zz,t;
int main() {
	//freopen("in.txt","r", stdin);
	rint(t);
	while(t--){
		rint(n) , rint(m) ;
		edgelist.clear();
		initSet (n);
		int ss = 0;
		repi(i,0,m)
		{
			rint(xx), rint(yy), rint(zz);
			edgelist.pb(mp(zz, ii(xx, yy)));
			ss += zz;
		}
		sort(edgelist.begin(), edgelist.end());
		reverse(edgelist.begin(),edgelist.end());
		int ret = 0;
		repi(i,0,m)
		{
			int t = _sc;
			unionSet(edgelist[i].s.f, edgelist[i].s.s);
			if (t == _sc)
				continue;
			else
				ret += edgelist[i].f;
			if (_sc == 1)
				break;
		}
		pint(ss - ret), pnl();
		//cout << _sc << endl;
	}
	return 0;
}
