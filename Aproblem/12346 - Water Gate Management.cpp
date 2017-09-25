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
ll rate[25];
ll cost[25];
int N, T;
ll NV, minC = INF_LL;
void backtrack(int inx, ll sum, ll ct) {
	if (sum * T >= NV) {
		minC = min(ct, minC);
		return;
	}
	if (inx == N) {
		if (sum * T >= NV) {
			minC = min(ct, minC);
		}
		return;
	}
	backtrack(inx + 1, sum + rate[inx], ct + cost[inx]);
	backtrack(inx + 1, sum, ct);
}

int main() {
	//freopen("in.txt", "r", stdin);
	int Q;
	rint(N);
	repi(i,0,N)
	{
		rl(rate[i]);
		rl(cost[i]);
	}
	rint(Q);
	int cnt = 0;
	while (Q--) {
		minC = INF_LL;
		rl(NV);
		rint(T);
		backtrack(0, 0, 0);
		printf("Case %d: ", ++cnt);
		if (minC == INF_LL) {
			printf("IMPOSSIBLE");
		} else {
			pl(minC);
		}
		pnl();
	}

	return 0;
}
