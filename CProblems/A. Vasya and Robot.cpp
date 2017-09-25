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
int arr[100100];
int sr[100100];
int sl[100100];
int main() {

	int n, l, r, ql, qr;
	scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
	repi(i,0,n)
		rint(arr[i + 1]);
	repi(i,0,n + 1)
		if (i > 1)
			sl[i] = sl[i - 1] + arr[i] * l;
		else
			sl[i] = arr[i] * l;

	for (int i = n ; i >= 0; i--)
		if (i < n)
			sr[i] = sr[i + 1] + arr[i + 1] * r;
		else
			sr[i] = arr[i + 1] * r;
	int ans = INF;
	for (int i = 0; i <= n; i++) {
		int nl = i, nr = n - i;
		if(nr == nl){
			ans = min(ans , sl[i] + sr[i]);
		}
		else if(nr  > nl){
			int dif = nr - nl - 1  ;
			ans = min(ans , sl[i] + sr[i] +  dif * qr);
		}else{
			int dif = nl - nr  - 1 ;
			ans = min(ans , sr[i] + sl[i] +  dif * ql);
		}
	}
	pint(ans);

	return 0;
}
