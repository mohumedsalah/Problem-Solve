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

inline void minto(int &a, int b)
{
	if (a > b)
		a = b;
}

const int MXL = 0x3f3f3f3f;
const int mxn = 100006;

char a[mxn], b[mxn], c[mxn];
int al, bl, cl;

int ra[128], rb[128], rc[128];


int main()
{
	scanf("%s%s%s", a, b, c);
	al = strlen(a);
	bl = strlen(b);
	cl = strlen(c);
	for (int i = 0; i < al; ++i)
		ra[a[i]]++;
	for (int i = 0; i < bl; ++i)
		rb[b[i]]++;
	for (int i = 0; i < cl; ++i)
		rc[c[i]]++;
	int ans = 0, ansb = 0, ansc = 0;
	for (int i = 0; ; ++i) {
		int t = MXL;
		for (int j = 'a'; j <= 'z'; ++j)
			if (rb[j] * i > ra[j])
				goto end;
		for (int j = 'a'; j <= 'z'; ++j) if (rc[j])
			minto(t, (ra[j] - rb[j] * i) / rc[j]);
		if (ans < i + t) {
			ans = i + t;
			ansb = i;
			ansc = t;
		}
	}
	end:;
	for (int i = 0; i < ansb; ++i)
		printf("%s", b);
	for (int i = 0; i < ansc; ++i)
		printf("%s", c);
	for (int i = 'a'; i <= 'z'; ++i) {
		ra[i] -= rb[i] * ansb + rc[i] * ansc;
		while (ra[i]--)
			printf("%c", i);
	}
	return 0;
}
