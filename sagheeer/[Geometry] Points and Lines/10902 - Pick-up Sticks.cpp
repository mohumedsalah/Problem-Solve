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

struct Point {
	double x;
	double  y;
	Point(double _x, double _y) :
			x(_x), y(_y) {

	}
};
vector<pair<Point, Point> > vp;
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y)
			&& q.y >= min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
	// See http://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1))
		return true;

	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1))
		return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2))
		return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2))
		return true;

	return false; // Doesn't fall in any of the above cases
}

vi ret;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	double x1, x2, y1, y2;
	while (rint(n) && n) {
		ret.clear();
		vp.clear();
		repi(i,0,n)
		{
			rf(x1), rf(y1);
			rf(x2), rf(y2);
			vp.push_back(mp(Point(x1, y1), Point(x2, y2)));
		}
		repi(i,0, n)
		{
			int fl = 1;
			repi(j,i + 1 ,n)
			{
				if (doIntersect(vp[i].f, vp[i].s, vp[j].f, vp[j].s)) {
					fl = 0;
					break;
				}

			}
			if (fl)
				ret.push_back(i + 1);
		}
		printf("Top sticks:");
		int sv = sz(ret);
		repi(i,0,sv)
		{
			if (i != sv - 1)
				psp(), pint(ret[i]), printf(",");
			else
				printf(" %d.", ret[i]);
		}
		pnl();
	}
	return 0;
}
