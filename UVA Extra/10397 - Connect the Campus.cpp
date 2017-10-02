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
ii arr[1010];
bool dis[1010][1010];
int r[1010], p[1010];
priority_queue<pair<double, ii>, vector<pair<double, ii> >, greater<pair<double, ii>> > q;
int findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	if (!isSameSet(i, j)) {
		int x = findSet(i), y = findSet(j);
		if (r[x] > r[y])
			p[y] = x;
		else {
			p[x] = y;
			if (r[x] == r[y])
				r[y]++;
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, xx, yy;
	while (cin >> n) {

		repi(i,0, n)
		{
			rint(arr[i].f);
			rint(arr[i].s);
		}
		repi(i,0,n+1){
			p[i] = i;
		}
		memset(r, 0, sizeof r);
		memset(dis, 0, sizeof dis);
		repi(i,0,n)
			repi(j,i+1, n)
				q.push(
						mp(hypot(arr[i].f - arr[j].f, arr[i].s - arr[j].s),
								ii(i + 1, j + 1)));

		rint(m);
		int num = 0;
		repi(i,0, m)
		{
			rint(xx), rint(yy);
			dis[xx][yy] = 1;
			if(!isSameSet(xx, yy)){
				num++;
			}
			unionSet(xx, yy);
		}
		int tt = n - 1 - num;
		pair<double, ii> cur;
		double ans = 0;
		while (tt) {
			cur = q.top();
			q.pop();
			if (dis[cur.s.f][cur.s.s] == 1 || isSameSet(cur.s.s, cur.s.f)) {
				continue;
			}
			unionSet(cur.s.f, cur.s.s);
			ans += cur.f;
			tt--;
		}
		while (q.size())
			q.pop();
		printf("%.2lf\n", ans);
	}

	return 0;
}
