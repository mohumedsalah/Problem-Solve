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

vector<vi> comps;
vi arr[1000];
int dfsnum[1000], comp[1000], dfslow[1000], instk[1000];
stack<int> stk;
int cntd = 0;
void scc(int inx) {
	dfslow[inx] = dfsnum[inx] = cntd++;
	stk.push(inx);
	instk[inx] = 1;
	repi(i,0, sz(arr[inx]))
	{
		int v = arr[inx][i];
		if (dfsnum[v] == -1) {
			scc(v);
			dfslow[inx] = min(dfslow[v], dfslow[inx]);
		} else if (instk[v]) {
			dfslow[inx] = min(dfslow[v], dfslow[inx]);
		}
	}
	if (dfslow[inx] == dfsnum[inx]) {
		comps.push_back(vector<int>());
		int x = -1;
		while (x != inx) {
			x = stk.top();
			stk.pop();
			comps.back().push_back(x);
			comp[x]= sz(comps) - 1;
		}
	}
	instk[inx] = 0;
}

int main() {

	memset(dfsnum, -1, sizeof dfsnum);
	int n,m,xx,yy;
	rint(n), rint(m);
	repi(i,0,n)
		arr[i].clear();
	comps.clear();
	repi(i,0,m){
		rint(xx), rint(yy);
		arr[xx].pb(yy);
	}
	scc(1);
	repi(i,0,sz(comps)){
		repi(j,0,sz(comps[i]))
				pint(comps[i][j]),psp();
		pnl();
	}

	return 0;
}
/*
 *
 *input like this
 *
 * 11 13
1 2
2 11
2 6
2 4
2 5
5 1
4 5
4 9
9 10
10 4
6 7
7 8
8 6
 */
