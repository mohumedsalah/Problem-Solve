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
#define pf(x) printf("%.2lf", x)
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
int r[250010], p[250010];
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
pair<double, ii> arr[250010];
int vis[510];
ii point[510];
int main() {
	//freopen("in.txt", "r", stdin);
	int t, n, m;
	rint(t);
	while (t--) {
		rint(m), rint(n);
		repi(i,0, n)
		{
			p[i] = i;
		}
		memset(vis, 0, sizeof vis);
		memset(r, 0, sizeof r);
		repi(i,0, n)
		{
			rint(point[i].f);
			rint(point[i].s);
		}
		int cnt = 0;
		repi(i,0, n)
		{
			repi(j,i + 1, n)
			{
				arr[cnt].f = hypot(point[i].f - point[j].f,
						point[i].s - point[j].s);
				arr[cnt].s.f = i, arr[cnt].s.s = j;
				cnt++;
			}
		}
		sort(arr, arr + cnt);
		int tt = n - 1;
		cnt = 0;
		m = n - m;
		double ans = 0;
		while (tt) {
			if (!isSameSet(arr[cnt].s.f, arr[cnt].s.s)) {
				unionSet(arr[cnt].s.f, arr[cnt].s.s);
				m--;
				if (m <= 0) {
					ans = arr[cnt].f;
					break;
				}

				tt--;
			}
			cnt++;
		}
		pf(ans), pnl();
	}

	return 0;
}
