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
vi vv[55];
int n , m, xx, nm;
int main(){
	cout << log2(3) << endl;
	rint(n), rint(m);
	repi(i,0, n){
		rint(nm);
		int fl = 0;
		int mxn = -INF;
		repi(j,0,nm){
			int b = 0;
			while(j < nm){
				rint(xx);
				if(xx >= 0)
					b += xx, fl = 1;
				else
					break;
				j++;
			}
			if(fl == 1)
				vv[i].pb(b);
			if(xx < 0 && !fl)
				mxn = min(mxn, xx);
		}
		if(!fl)
			vv[i].pb(mxn);
	}
	ll cur = 0, mx = 0;
	int  fl = 0, mostne = -INF;
	repi(i,0, m){
		rint(xx);
		xx--;
		repi(j,0, sz(vv[xx])){
			if(cur + vv[xx][j] < 0){
				mostne = max(mostne, vv[xx][j]);
				cur = 0;
				continue;
			}
			fl = 1;
			cur += vv[xx][j];
			mx = max(mx, cur);
		}
	}
	if(fl == 1)
		pl(mx);
	else
		pint(mostne);


	return 0;
}
