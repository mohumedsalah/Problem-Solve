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

int main() {
	int n, t;
	rint(n);
	t = n / 2 + 1;
	repi(i,0,t)
	{
		repi(j,0,t - i - 1)
			cout << '*';
		repi(j,0,2*i + 1)
			cout << 'D';
		repi(j,0,t-i-1)
			cout << '*';
		pnl();
	}
	repi(i,0,t-1)
	{
		repi(j,0,i+1)
			cout << '*';
		repi(j,0,t-i-1)
			cout << 'D';
		repi(j,0,t-i-2)
			cout << 'D';
		repi(j,0,i+1)
			cout << '*';
		if(i != t-2)
			pnl();
	}
	return 0;
}
