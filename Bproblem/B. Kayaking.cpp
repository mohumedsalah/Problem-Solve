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
typedef pair<int,pair<int, int> > iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
int arr[110];

priority_queue<iii , vector<iii>, greater<iii> > q;
int cal[110];
int main(){

	int n;
	rint(n);
	repi(i,0,(2*n)){
		rint(arr[i]);
	}
	sort(arr, arr + 2*n);
	int ans = INF;
	repi(fb, 0 , 2*n){
		repi(sb,fb + 1, 2*n){
			int cnt = 0, ret = 0;
			repi(i,0, 2*n){
				if(i == fb || i == sb)
					continue;
				cal[cnt] = arr[i];
				cnt++;
			}
			repi(i,0,2*( n - 1)){
				ret += abs(cal[i] - cal[i + 1]);
				i++;
			}
			ans = min(ret, ans);
		}
	}
	pint(ans);
	return 0;
}
