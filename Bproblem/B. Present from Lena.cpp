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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

	int n;
	rint(n);
	repi(i,0,n + 1)
	{
		repi(j,0,n-i)
		{
			psp(), psp();
		}
		repi(j,0,i)
		{
			pint(j), psp();
		}
		for (int j = i; j >= 0; j--) {
			if (j == 0)
				pint(j);
			else
				pint(j), psp();
		}
		pnl();
	}
	repi(i,0,n)
	{
		repi(j,-1,i)
		{
			psp(), psp();
		}
		repi(j,0,n - i)
		{

			pint(j);
			if (i != n - 1)
				psp();
		}
		repi(j,0,n-i - 1)
		{
			if (j == n - i - 1 - 1)
				pint(n - j - i - 2);
			else
				pint(n-j-i - 2), psp();
		}
		if (i != n - 1)
			pnl();
	}

	return 0;
}
