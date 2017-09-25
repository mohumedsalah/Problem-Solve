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
int n, q,xx;
int arr[10010];
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w", stdout);
	int cnt = 0;
	while (rint(n),rint(q) && n && q) {
		repi(i,0,n)
		{
			rint(arr[i]);
		}
		sort(arr, arr + n);

		printf("CASE# %d:\n",++cnt);
		while(q--){

			rint(xx);
			int st = 0, e = n,ans = -1;
			while(st - 1 < e){
				int m = (st+e)/2;
				if(arr[m] == xx){
					 ans = m + 1;
					 e = m - 1;
				}else if(arr[m] > xx){
					e = m - 1;
				}else if(arr[m] < xx){
					st = m + 1;
				}
			}
			if(ans == -1){
				printf("%d not found",xx);
			}else{
				printf("%d found at %d",xx,ans);
			}
			pnl();
		}
	}

	return 0;
}
