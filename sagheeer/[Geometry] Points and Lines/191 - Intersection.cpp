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

class point {
public:
	int x, y;
	point(int _x, int _y) {
		x = _x, y = _y;
	}
	point() {
		x = y = 0.0;
	}
};

int turn(point O, point A, point B) {
	double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
	if (res < 0)
		return -1; // O->A->B is a right turn
	if (res > 0)
		return 1; // O->A->B is a left turn
	return 0; // O->A->B is a straight line / co-linear
}

inline bool onSegment(const point &p1, const point &p2, const point &p3) {
	point pmn, pmx;
	pmn.x = min(p1.x, p2.x), pmn.y = min(p1.y, p2.y);
	pmx.x = max(p1.x, p2.x), pmx.y = max(p1.y, p2.y);
	return pmn.x <= p3.x && p3.x <= pmx.x && pmn.y <= p3.y && p3.y <= pmx.y;
}

bool Intersect(point &p1, point &p2, point &p3, point &p4) {
	int d1, d2, d3, d4;
	d1 = turn(p3, p4, p1);
	d2 = turn(p3, p4, p2);
	d3 = turn(p1, p2, p3);
	d4 = turn(p1, p2, p4);
	if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0))
			&& ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)))
		return true;
	if (!d3 && onSegment(p1, p2, p3)) {
		return true;
	}
	if (!d4 && onSegment(p1, p2, p4))
		return true;
	if (!d1 && onSegment(p3, p4, p1))
		return true;
	if (!d2 && onSegment(p3, p4, p2))
		return true;
	return false;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t;
	rint(t);
	while (t--) {
		point p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		point arr[4];
		cin >> arr[0].x >> arr[0].y >> arr[2].x >> arr[2].y;
		arr[1].x = arr[0].x, arr[1].y = arr[2].y;
		arr[3].x = arr[2].x, arr[3].y = arr[0].y;
		if (arr[0].x <= p1.x && arr[0].x <= p2.x && arr[2].x >= p1.x
				&& arr[2].x >= p2.x && arr[0].y >= p1.y && arr[0].y >= p2.y
				&& arr[2].y <= p1.y && arr[2].y <= p2.y) {
			puts("T");
			continue;
		}
		int fl = 1;
		repi(i,0,3)
		{
			if (Intersect(p1, p2, arr[i], arr[i + 1])) {
				fl = 0;
			}
		}
		if (Intersect(p1, p2, arr[3], arr[0])) {
			fl = 0;
		}
		if (fl)
			puts("F");
		else
			puts("T");
	}
	return 0;
}
