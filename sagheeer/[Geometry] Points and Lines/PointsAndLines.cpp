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
#define pf(x) printf("%.15lf", x)
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
#define EPS 1e-9
#define mod 1000000007
#define pb push_back
#define mp make_pair
const double PI = 2 * acos(0.0);
#define PI acos(-1.0)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	bool operator <(point other) const {
		if (fabs(other.x - x) < EPS) {
			return y < other.y;
		} else {
			return x < other.x;
		}
	}
	bool operator ==(point other) const {
		return (fabs(other.x - x) < EPS) && (fabs(y - other.y) < EPS);
	}

};

struct line {
	double a, b, c;
};

double dist(point p1, point p2) {
// Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);
// multiply theta with PI / 180.0
	return point(p.x * cos(rad) - p.y * sin(rad),
			p.x * sin(rad) + p.y * cos(rad));
}

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
// vertical line is fine
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
// default values
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
// IMPORTANT: we fix the value of b to 1.0
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2) {
// check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
// also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2))
		return false;
// no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}

int main() {

	pf(PI);

	priority_queue<point> q;
	q.push(point(1, 2));
	q.push(point(3, 2));
	q.push(point(2, 1));
	point p1 = point(5.0, 5.0);
	point p2 = point(5.0, 5.0);

	cout << (p1 == p2) << endl;
	while (q.size()) {
		point xx = q.top();
		cout << xx.x << " " << xx.y << endl;
		q.pop();
	}
	return 0;
}
