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
char arr[1010][510];
int larr[1010];
char q[100000];
int main() {
	freopen("in.txt","r", stdin);
	int D, Q, l,dif, mindif, ans,mmdif,n,j,k;
	rint(D), rint(Q);

	repi(i,0,D)
	{
		rs(arr[i]);
		larr[i]= ssz(arr[i]);
	}
	while (Q--) {
		rs(q);
		 n = ssz(q);
		 ans = -1, mmdif = 100000000;
		repi(i,0,D)
		{
			l = larr[i];
			if (n > l)
				continue;
			 mindif = 100000000;
			for ( j = 0; j < l - n + 1; j++) {

				 dif = 0;
				for ( k = 0; k < n; k++) {
					if (arr[i][k + j] != q[k]) {
						dif++;
					}
				}
				mindif = min(dif, mindif);
			}
			if (mindif < mmdif) {
				ans = i;
				mmdif = mindif;
			}
		}
		ans++;
		pint(ans),pnl();
	}

	return 0;
}
