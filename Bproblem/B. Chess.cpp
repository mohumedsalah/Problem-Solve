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
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
char str[5];
int x1, y, x2, y2;
bool inBox(int i, int j) {
	return i >= 1 && j >= 1 && i <= 8 && j <= 8;
}
bool che(int i, int j) {
	repi(d,0,8)
	{
		int ni = x2 + dx[d], nj = y2 + dy[d];
		if (inBox(ni, nj) && i == ni && j == nj)
			return false;
	}

	repi(d,0,8)
	{
		int ni = i + dx[d], nj = j + dy[d];
		if (inBox(ni, nj) && ni == x2 && nj == y2)
			return false;
	}
	repi(d,0,8)
	{
		int ni = i + dx[d], nj = j + dy[d];
		if (inBox(ni, nj) && ni == x1 && nj == y)
			return false;
	}
	return true;
}
int main() {

	rs(str);
	x1 = (str[0] - 'a') + 1;
	y = str[1] - '0';
	getchar();
	rs(str);
	x2 = (str[0] - 'a') + 1;
	y2 = str[1] - '0';
	//cout << x1 << y << x2 << y2 << endl;
	int ret = 0;
	repi(i,1,9)
	{
		repi(j,1,9)
		{
			if (i == x1 || j == y)
				continue;
			if (i == x2 && j == y2)
				continue;
			ret += che(i, j);
		}
	}
	pint(ret);

	return 0;
}
