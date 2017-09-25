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
int ret[200][9];
int save[9];
int cnt = 0;
int grid[9][9];
bool place(int r, int c) {
	for (int prev = 1; prev < c; prev++)
		if (save[prev] == r || (abs(save[prev] - r) == abs(prev - c)))
			return false;
	return true;
}
void backtraik(int inx) {
	if (inx == 9) {
		repi(i,1,9)
			ret[cnt][i] = save[i];
		cnt++;
		return;
	}
	repi(i,1,9)
	{
		if (place(i, inx)) {
			save[inx] = i;
			backtraik(inx + 1);
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	backtraik(1);
	int T;
	rint(T);
	while (T--) {
		repi(i,1,9)
			repi(j,1,9)
				rint(grid[i][j]);
		ll ans = 0;
		repi(i,0,cnt)
		{
			ll rett = 0;
			repi(j,1,9)
				rett += grid[j][ret[i][j]];
			ans = max(rett, ans);
		}
		cout << setw(5) << setiosflags(ios::right) << ans << endl;
	}
	return 0;
}

