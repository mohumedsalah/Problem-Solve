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
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char arr[100010];
int vis[100010];
int main() {
	rs(arr);
	int n = ssz(arr);
	int fl1 = 0, fl2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == 'A' && arr[i + 1] == 'B' && !vis[i] && !vis[i + 1]
				&& !fl1) {
			fl1 = vis[i] = vis[i + 1] = 1;

		}
		if (arr[i] == 'B' && arr[i + 1] == 'A' && !vis[i] && !vis[i + 1]
				&& !fl2) {
			fl2 = vis[i] = vis[i + 1] = 1;
		}
	}
	if (fl1 && fl2){
			puts("YES");
			return 0;
	}
	fl1 = fl2 = 0;
	memset(vis, 0, sizeof vis);
	for (int i = n; i > 0; i--) {
		if (arr[i] == 'A' && arr[i - 1] == 'B' && !vis[i] && !vis[i - 1]
				&& !fl1) {
			fl1 = vis[i] = vis[i - 1] = 1;

		}
		if (arr[i] == 'B' && arr[i - 1] == 'A' && !vis[i] && !vis[i - 1]
				&& !fl2) {
			fl2 = vis[i] = vis[i - 1] = 1;
		}
	}
	if (fl1 && fl2)
		puts("YES");
	else
		puts("NO");

	return 0;
}
