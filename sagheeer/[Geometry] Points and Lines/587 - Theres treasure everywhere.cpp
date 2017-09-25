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
#define EPS 1e-8
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
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

};
double dis(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	string xx, np;
	int cnt = 0;
	while (getline(cin, xx) && xx != "END") {
		point p = point(0.0, 0.0);
		stringstream sinn(xx);
		while (getline(sinn, np, ',')) {

			n = np.size();
			if (np[n - 1] == '.')
				n--;
			int i;
			int dis = 0;
			for (i = 0; i < n && np[i] >= '0' && np[i] <= '9'; i++) {
				dis = dis * 10 + (np[i] - '0');
			}
			if (i == n - 1) {
				if (np[i] == 'N') {
					p.y += dis;
				} else if (np[i] == 'S') {
					p.y -= dis;
				} else if (np[i] == 'W') {
					p.x -= dis;
				} else {
					p.x += dis;
				}
			} else {
				if (np[i] == 'N' && np[i + 1] == 'E') {
					p.y += sin(PI / 4.0) * double(dis);
					p.x += cos(PI / 4.0) * double(dis);
				} else if (np[i] == 'N' && np[i + 1] == 'W') {
					p.y += sin(PI / 4.0) * double(dis);
					p.x -= cos(PI / 4.0) * double(dis);
				} else if (np[i] == 'S' && np[i + 1] == 'E') {
					p.y -= sin(PI / 4.0) * double(dis);
					p.x += cos(PI / 4.0) * double(dis);
				} else {
					p.y -= sin(PI / 4.0) * double(dis);
					p.x -= cos(PI / 4.0) * double(dis);
				}
			}
		}
		printf("Map #%d\n", ++cnt);
		printf("The treasure is located at (%.3lf,%.3lf).\n", p.x, p.y);
		printf("The distance to the treasure is %.3lf.\n\n",
				dis(point(0.0, 0.0), p));
	}
	//cout << xx << endl;
	return 0;

}
