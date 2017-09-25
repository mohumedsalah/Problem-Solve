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
int n, m;
vii arr[505];
int xx, yy, zz, dis[505][2];

struct node {
	int c;
	int inx;
	bool state;
};
node mn(int a, int b, int c) {
	node n;
	n.c = a, n.inx = b, n.state = c;
	return n;
}
bool operator <(node a, node b) {
	if (a.c == b.c)
		return a.inx > b.inx;
	return a.c > b.c;
}

priority_queue<node> pq;
int main() {
	//freopen("in.txt","r", stdin);
	int cnt = 0;
	while (cin >> n) {
		rint(m);
		repi(i,0,n)
			arr[i].clear(),dis[i][0] = INF, dis[i][1] = INF;
		while (pq.size())
			pq.pop();

		repi(i,0,m)
		{
			rint(xx), rint(yy), rint(zz);
			arr[xx].pb(ii(yy, zz));
			arr[yy].pb(ii(xx, zz));
		}
		pq.push(mn(0,0,1));
		node cur;
		while(pq.size()){
			cur = pq.top();
			pq.pop();
			repi(i,0, sz(arr[cur.inx])){
				ii chv = arr[cur.inx][i];
				if(dis[chv.f][!cur.state] > cur.c + chv.s ){
					dis[chv.f][!cur.state] = cur.c + chv.s ;
					pq.push(mn(cur.c + chv.s,chv.f,!cur.state));
				}
			}
		}
		printf("Set #%d\n",++cnt);
		if(dis[n-1][1] == INF)
			puts("?");
		else
			pint(dis[n-1][1]),pnl();
	}
	return 0;
}
