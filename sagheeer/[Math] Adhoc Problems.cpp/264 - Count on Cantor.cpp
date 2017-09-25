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
int const mx = 1e7 + 9;
ii arr[mx + 10];
int n;
int main() {
	//freopen("in.txt","r", stdin);
	int cnt = 1;
	while (true) {
		int fl = 0;
		repi(i,1,mx)
		{
			fl = !fl;
			repi(j,1,i + 1)
			{
				if(!fl)
				arr[cnt].f = j, arr[cnt].s = i + 1 - j;
				else
				arr[cnt].s = j, arr[cnt].f = i + 1 - j;
				cnt++;
				if (cnt > mx)
					break;
			}
			if (cnt > mx)
				break;
		}
		if (cnt > mx)
			break;
	}
	while (cin >> n) {
		printf("TERM %d IS %d/%d\n", n, arr[n].f, arr[n].s);
	}

	return 0;
}
