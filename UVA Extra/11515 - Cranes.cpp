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
struct point {
	int x, y, c;

};

point mdp(int _x, int _y, int _c) {
	point p;
	p.x = _x, p.y = _y, p.c = _c;
	return p;
}
point arr[20];
int t, n, xx, yy, zz;
ll ans;
vector<int> vv;
void solve(int inx, ll ss) {
	if (inx == n + 1) {
		ans = max(ans, ss);
		return;
	}
	int fl = 1;
	repi(i,0, sz(vv))
	{
		double temp = hypot(arr[inx].x - arr[vv[i]].x,
				arr[inx].y - arr[vv[i]].y);
		double temp2 = double(arr[inx].c) + arr[vv[i]].c;
		if (temp > temp2)
			continue;
		fl = 0;
		break;
	}
	if (fl) {
		vv.pb(inx);
		solve(inx + 1, ss + (arr[inx].c * arr[inx].c));
		vv.pop_back();
	}
	solve(inx + 1, ss);

}
int main() {
	//freopen("in.txt", "r", stdin);

	rint(t);
	while (t--) {
		ans = -INF;
		rint(n);
		arr[0].x = arr[0].y = arr[0].c = 0;
		repi(i,0,n)
		{
			rint(xx), rint(yy), rint(zz);
			arr[i + 1] = mdp(xx, yy, zz);
		}
		solve(0, 0);
		pl(ans), pnl();

	}

	return 0;
}
