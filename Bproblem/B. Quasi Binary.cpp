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
int arr[500][50];
int main() {
	char str[100];
	rs(str);
	int n = ssz(str);
	int mxd = 0;
	repi(i,0,n)
	{
		mxd = max(mxd, (str[i] - '0'));
	}
	repi(i,0,n)
	{
		int tt = str[i] - '0';
		repi(j,0,mxd)
		{
			if (tt > 0)
				arr[j][i] = 1;
			tt--;
		}
	}
	cout << mxd << endl;
	repi(i,0,mxd)
	{
		int fl = 0;
		repi(j,0,n)
		{
			if (fl || arr[i][j]) {
				cout << arr[i][j];
				fl = 1;
			}
		}
		psp();
	}

	return 0;
}
