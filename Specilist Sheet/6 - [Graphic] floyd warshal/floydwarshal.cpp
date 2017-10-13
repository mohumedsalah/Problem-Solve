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
int arr[1000][1000];
int path[1000][1000];
void build_pah(int src, int des){
	if(path[src][des] == -1){
		cout << src << " ";
		return;
	}
	build_pah(src,path[src][des]);
	build_pah(path[src][des], des);

}
int main(){
	freopen("in.txt","r", stdin);
	memset(path, -1 , sizeof path);
	int n , m, xx ,yy,zz;
	rint(n), rint(m);
	repi(i,0,n)repi(j,0,n)
			arr[i][j]= INF;
	repi(i,0, m){
		rint(xx), rint(yy), rint(zz);
		arr[xx][yy] = zz;
	}
	repi(i,1,n + 1)
		arr[i][i] = 0;
	repi(k,1, n + 1)repi(i,1, n + 1)repi(j,1,n + 1)
			if(arr[i][k] < INF && arr[k][j] < INF){
				if(arr[i][j] <=  arr[i][k] + arr[k][j]){
					continue;
				}else{
					path[i][j] = k;
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
	int q;
	rint(q);
	while(q--){
		rint(xx),rint(yy);
		printf("Cost is %d\n",arr[xx][yy]);
		build_pah(xx, yy);
		cout << yy << endl;
	}
	return 0;
}
