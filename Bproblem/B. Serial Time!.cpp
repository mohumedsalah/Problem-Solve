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
char arr[110][110][110];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
int vis[110][110][110];
int k , n, m;
bool inBox(int z, int i, int j){
	return z >= 0 && z < k && i >= 0 && i < n && j >= 0 && j < m && arr[z][i][j] =='.';
}
int ans = 0;
void solve(int z, int i , int j){
	vis[z][i][j] = 1;
	ans++;
	repi(rr,0,6){
		int nz = z + dz[rr];
		int ni = i + dx[rr];
		int nj = j + dy[rr];
		if(inBox(nz,ni, nj) && vis[nz][ni][nj] == 0){
			solve(nz, ni, nj);
		}
	}
}
int main(){


	rint(k), rint(n),rint(m);
	repi(i,0, k){
		repi(r,0,n){
			rs(arr[i][r]);
		}
	}
	int xx, yy;
	rint(xx), rint(yy);
	solve(0,xx - 1, yy - 1);
	pint(ans);

	return 0;
}
