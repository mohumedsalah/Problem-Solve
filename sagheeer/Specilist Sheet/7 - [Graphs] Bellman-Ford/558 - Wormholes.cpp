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
vii arr[12340];
int dis[12340];
int main(){
	//freopen("in.txt","r", stdin);
	int t, n ,m,xx, yy, zz;
	rint(t);
	while(t--){

		rint(n), rint(m);
		repi(i,0, n)
			arr[i].clear(),dis[i] = INF;
		repi(i,0,m){
			scanf("%d%d%d",&xx,&yy,&zz);
			arr[xx].pb(ii(yy, zz));
		}
		dis[0] = 0;
		repi(i,0,n-1)
			repi(u,0,n)
				repi(j,0,sz(arr[u])){
					ii v = arr[u][j];
					dis[v.f] = min(dis[v.f] , dis[u] + v.s);
				}
		int fl = 1;
		repi(u,0, n)
			repi(j,0, sz(arr[u])){
				ii v = arr[u][j];
				if(dis[v.f] > dis[u] + v.s)
					fl = 0;
			}
		if(!fl)
			puts("possible");
		else
			puts("not possible");



	}


	return 0;
}
