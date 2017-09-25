#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%I64d",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%I64d", x)
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
//#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, int> mp;
map<ll, int> mp1;
map<ll, int> mp2;
map<ll, int>::iterator it;
map<ll, int>::iterator it1;
map<ll, int>::iterator it2;
int n;
ll xx;
int main() {

	rint(n);
	repi(i,0,n)
	{
		rl(xx);
		mp[xx]++;
	}

	repi(i,0,n-1)
	{
		rl(xx);
		mp1[xx]++;
	}
	for (it = mp.begin(); it != mp.end(); it++) {
		it1 = mp1.find(it->f);
		if (it->s == it1->s)
			continue;
		pl(it->f), pnl();
		break;
	}
	repi(i,0,n-2)
	{
		rl(xx);
		mp2[xx]++;
	}
	for (it1 = mp1.begin(); it1 != mp1.end(); it1++) {
		it2 = mp2.find(it1->f);
		if (it1->s == it2->s)
			continue;
		pl(it1->f), pnl();
		break;
	}

	return 0;
}
