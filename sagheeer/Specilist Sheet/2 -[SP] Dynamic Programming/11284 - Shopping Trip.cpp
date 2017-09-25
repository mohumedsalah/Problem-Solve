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
typedef pair<int, double> ii;
typedef pair<double, int> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
int n, m, p;
vii graph[55];
double dis[55][55];
int arr[55];
int viss[55];
double fsp(int st, int ed) {
	memset(viss, -1, sizeof viss);
	priority_queue<iii> q;
	q.push(iii(0, st));
	viss[st] = 1;
	while (q.size()) {
		iii cur = q.top();
		q.pop();
		if (cur.s == ed)
			return cur.f;
		repi(i,0,sz(graph[cur.s]))
		{
			int che = graph[cur.s][i].f;
			if (viss[che] == -1) {
				viss[che] = 1;
				q.push(iii(cur.f + graph[cur.s][i].s, che));
			}
		}
	}
	return -1;
}
bool eq(double a, double b) {
	return (fabs(a - b) <= EPS);
}
double memo[55][55];
double tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
  if (bitmask == (1 << (p + 1)) - 1)
    return dis[pos][0]; // return trip to close the loop
  if (!eq(memo[pos][bitmask],-1))
    return memo[pos][bitmask];

  double ans = 2000000000.0;
  for (int nxt = 0; nxt <= p; nxt++) // O(n) here
    if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
      ans = min(ans, dis[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	int t, xx, yy;
	double zz;
	rint(t);
	while (t--) {
		repi(i,0,20)
		{
			repi(j,0,20)
			{
				memo[i][j] = -1;
			}
		}
		rint(n), rint(m);
		repi(i,0,n + 1)
		{
			graph[i].clear();
		}
		repi(i,0,m)
		{
			rint(xx), rint(yy), rf(zz);
			graph[xx].pb(ii(yy, zz));
			graph[yy].pb(ii(xx, zz));
		}


		rint(p);
		double cost = 0;
		arr[0] = 0;
		set<int> ss;
		int xxx;
		repi(i,1,p+1){
			rint(xxx), rf(zz);
			ss.insert(xxx);
			cost += zz;
		}
		p = ss.size();
		repi(i,1,p + 1)
		{
			arr[i] = *ss.begin();
			ss.erase(*ss.begin());
			repi(j,0,i)
			{
				if (arr[i] != arr[j]) {
					dis[j][i] = dis[i][j] = fsp(arr[i], arr[j]);
				}
			}
		}
		double ret = tsp(0, 1);
		//pf(ret), pnl();
		if (ret < cost) {
			printf("Daniel can save $%.2lf\n", cost - ret);
		} else {
			printf("Don't leave the house\n");
		}
	}

	return 0;
}
