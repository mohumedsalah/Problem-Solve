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
int r[10], rd[20], ld[20];
int c[10];
int tc, tr;
int cnt;
int sol[100][100];
void backtrack(int cinx) {
	if (cinx == tc ) {
		if (r[tr] == 0 && rd[tr - cinx + 8] == 0 && ld[tr + cinx] == 0) {
		r[tr] = rd[tr - cinx + 8] = ld[tr + cinx] = 1;
		c[cinx] = tr;
		backtrack(cinx + 1);
		c[cinx] = r[tr] = rd[tr - cinx + 8] = ld[tr + cinx] = 0;
		}
		return;
	}
	if (cinx == 9) {
		repi(i,1,9)
			sol[cnt][i] = c[i];
		cnt++;
		return;
	}
	repi(row,1,9)
	{

		if (r[row] == 0 && rd[row - cinx + 8] == 0 && ld[row + cinx] == 0) {
			r[row] = rd[row - cinx + 8] = ld[row + cinx] = 1;
			c[cinx] = row;
			backtrack(cinx + 1);
			c[cinx] = r[row] = rd[row - cinx + 8] = ld[row + cinx] = 0;
		}
	}
}
int main() {
	//freopen("in.txt","r", stdin);
	int T;
	rint(T);
	while (T--) {
		int cc = 0;
		printf("SOLN       COLUMN");
		pnl();
		printf(" #      1 2 3 4 5 6 7 8");
		pnl();
		pnl();
		rint(tr),rint(tc);
		memset(r, 0, sizeof r);
		memset(rd, 0, sizeof rd);
		memset(ld, 0, sizeof ld);
		cnt = 0;
		backtrack(1);

		repi(i,0,cnt){
			cout << setw(2) << setiosflags(ios::right) << ++cc << "      " ;
			repi(j,1,9){
				pint(sol[i][j]);
						if(j == 8)
							pnl();
						else
							psp();
			}
		}
		if(T != 0)
		pnl();
	}
	return 0;
}
