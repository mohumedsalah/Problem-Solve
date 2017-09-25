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
int vis[1100];
string str,a;
int main(){
	int n, m, tt , inx, ans = 0;
	rint(n),rint(m);
	int mxr = 0 , mnl = n + 1;
	getchar();
	repi(i,0, m){
		getline(cin , str);
		stringstream sin(str);
		sin >> a >> a >> a;
		//cout << a << endl;
		if(a == "left"){
			tt = -1;
		}else{
			tt = +1;
		}sin >> a ;
		sin >> inx;
		//cout << inx << endl; ;
		if(inx + tt > 0 && inx+tt <= n){
			if(tt == -1)
				mnl = min(mnl, inx);
			else
				mxr = max(mxr, inx);
		}else{
			puts("-1");
			return 0;
		}
	}
	//cout << mxr << " " << mnl << endl;
	ans = mnl - mxr - 1 ;
	if(ans <= 0)
		puts("-1");
	else
		pint(ans);


	return 0;
}
