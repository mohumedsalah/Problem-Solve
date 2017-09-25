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
int const mx = 1e5 + 5;
double x[mx];
double y[mx];
double diss[mx];

double x1, yy, x2, y2, x3, y3;
int main() {
	freopen("in.txt","r", stdin);
	cin >> x1 >> yy >> x2 >> y2 >> x3 >> y3;

	int n;
	rint(n);
	double ret = 0;
	repi(i,0,n)
	{
		rf(x[i]), rf(y[i]);
		ret += hypot(x[i] - x3, y[i] - y3) * 2;
	}
	double ans = double(INF_LL);
	int fl = -1;
	int inxm = -1;
	repi(i,0,n)
	{
		double disa = ret - hypot(x[i] - x3, y[i] - y3) + hypot(x[i] - x1, y[i] - yy);
		double disb = ret - hypot(x[i] - x3, y[i] - y3) + hypot(x[i] - x2, y[i] - y2);

		if(ans > disa){
			ans = disa;
			fl = 0;
			inxm = i;
		}if(ans > disb){
			ans = disb;
			fl = 1;
			inxm = i;
		}
	}
	repi(i,0,n){
		if(i == inxm)
			continue;
		if(fl){
			ans = min(ans, ans - hypot(x[i] - x3, y[i] - y3) + hypot(x[i] - x1, y[i] - yy));
		}else{
			ans = min(ans, ans - hypot(x[i] - x3, y[i] - y3) + hypot(x[i] - x2, y[i] - y2));
		}
	}
	pf(ans);

	return 0;
}
