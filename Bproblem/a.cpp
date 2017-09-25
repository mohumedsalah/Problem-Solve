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
vi arr[100010];
int vis[100010];
ll solve(int inx , int fl ){
	if(vis[inx] != -1)
		return 0;
	vis[inx]  = fl;
	ll ret = 0;
	repi(i,0, sz(arr[inx])){
		ret += solve(arr[inx][i], !fl);
	}
	return ret;
}
int main(){

	int n , xx, yy;
	memset(vis, -1 , sizeof vis);
	rint(n);
	repi(i,0, n- 1){
		rint(xx), rint(yy);
		arr[xx].pb(yy);
		arr[yy].pb(xx);
	}
	solve(1, 0);
	ll nb = 0, nw = 0;
	repi(i,1, n + 1){
		if(vis[i] == 0)
			nb++;
		else
			nw++;
	}
	//cout << nb << " " << nw << endl;
	ll ret = nb * nw - ((n - 1ll));
	cout << ret << endl;
	return 0;
}
