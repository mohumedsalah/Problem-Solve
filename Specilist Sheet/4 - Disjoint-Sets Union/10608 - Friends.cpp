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
vi arr[30010];
int vis[30010];
int n , m,xx,yy;
int dfs(int inx){
	if(vis[inx])
		return 0;
	vis[inx] = 1;
	int ans = 0;
	repi(i,0,sz(arr[inx])){
		if(!vis[arr[inx][i]])
			ans += dfs(arr[inx][i]) + 1;
	}
	return ans;
}
int main(){
	//freopen("in.txt","r", stdin);
	int t;
	rint(t);
	while(t--){
		rint(n), rint(m);
		repi(i,0, n){
			arr[i+1].clear();
		}
		memset(vis, 0, sizeof vis);
		repi(i,0, m){
			rint(xx), rint(yy);
			arr[xx].pb(yy);
			arr[yy].pb(xx);
		}
		int ans = 0;
		repi(i,0, n){
			if(vis[i + 1])
				continue;
			ans = max(ans , dfs(i + 1));
		}
		pint(ans + 1), pnl();
	}

	return 0;
}
