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
int N, M, ret = -1;
vector<int> vans;
vector<int> track;
int arr[25];
int vis[25];
int dp[25][1000];
void backtraking(int inx, int sum) {
	if (sum > M)
		return;
	if (inx == N) {
		if (sum > ret) {
			vans.clear();
			repi(i,0,sz(track))
				vans.push_back(track[i]);
			ret = sum;
		}
		return;
	}

	track.push_back(arr[inx]);
	backtraking(inx + 1, sum + arr[inx]);
	track.pop_back();

	backtraking(inx + 1, sum);

}
int main() {
	//freopen("in.txt", "r", stdin);
	while (cin >> M) {
		memset(dp, -1, sizeof dp);
		vans.clear();
		track.clear();
		ret = 0;
		memset(vis, -1, sizeof vis);
		rint(N);
		repi(i,0,N)
			rint(arr[i]);
		backtraking(0, 0);
		int n = sz(vans);
		repi(i,0,n)
			pint(vans[i]), psp();
		printf("sum:%d", ret);
		pnl();
	}
	return 0;
}
