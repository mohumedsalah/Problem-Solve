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
int cum[110][110];
int xx2[110],yy2[110],yy3[110],xx3[110];
bool che( int x , int y,int x1, int y1 , int x2, int y2,int x3 , int y3){
	return ((x2 < x && x3 < x) || (x2 > x1 && x3 > x1)) || ((y2 < y && y3 < y) || (y2 > y1 && y3 >y) );
}

int main(){
	//freopen("in.txt","r", stdin);
	int t,q,n;
	repi(i,0,110)repi(j,0,110){
		cum[i][j]=1;
		if(i > 0)cum[i][j] += cum[i-1][j];
		if(j > 0)cum[i][j] += cum[i][j-1];
		if(i >0 && j > 0)cum[i][j] -= cum[i-1][j-1];
	}
	rint(t);
	while(t--){
		rint(n);
		rint(q);
		repi(i,0,q){
			rint(xx2[i]),rint(yy2[i]), rint(xx3[i]), rint(yy3[i]);
			xx2[i]--, xx3[i]--, yy2[i]--, yy3[i]--;
		}
		int mx = -INF;
		repi(x,0,n)repi(xx,x,n)repi(y,0,n)repi(yy,y,n){
			int fl = 1;
			repi(i,0,q){
				if(!che(x,y,xx,yy,xx2[i],yy2[i], xx3[i],yy3[i])){
					fl = 0;
					break;
				}
			}
			if(fl){
				int ret = cum[xx][yy];
				if(x > 0) ret -= cum[x - 1][yy];
				if(y > 0)ret -= cum[xx][y-1];
				if(x > 0 && y > 0) ret += cum[x - 1][y - 1];
				mx = max(mx , ret);
			}
		}
		if(mx == -INF)
			puts("0");
		else
			pint(mx),pnl();

	}

	return 0;
}
