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
struct point {
	double x, y;
	point(double _x, double _y) :
			x(_x), y(_y) {

	}
	bool operator <(point p) const {
		if (fabs(x - p.x) < EPS)
			return y > p.x;
		return x > p.x;
	}
};
vector<point> vp;
struct line {
	double a, b, c;
	line(double _a, double _b, double _c) :
			a(_a), b(_b), c(_c) {
	}
};
void getEqutionFromPoints(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}
bool areParallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2))
		return false;

	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}
double dis(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
int main() {
	int t, n, xx, yy;
	rint(t);
	while (t--) {
		vp.clear();
		rint(n);
		repi(i,0,n)
		{
			rint(xx), rint(yy);
			vp.push_back(point(double(xx), double(yy)));
		}
		sort(vp.begin(), vp.end());


		int mxy = vp[0].y;
		double ret = 0;
		repi(i,1,sz(vp)){
			if( vp[i].y > mxy){
				line lin = line(0.0,0.0,0.0);
				getEqutionFromPoints(vp[i],vp[i-1],lin);
				double xxx = (-(lin.b *mxy + lin.c)) / lin.a;
				point np = point(xxx,mxy);
				ret += dis(vp[i], np);
				mxy = vp[i].y;
			}
		}
		pf(ret),pnl();
	}

	return 0;
}
