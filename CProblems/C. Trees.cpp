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
int arr[123456];
int ifans[123456];
int main() {

	int n;
	rint(n);
	int t = ceil(n / 2.0);
	repi(i,0, n)
	{
		rint(arr[i]);
	}
	repi(i, 0 , t)
	{
		if ((arr[i] - i) > 0) {
			ifans[arr[i] - i]++;
		}
	}
	repi(i, t , n)
	{
		if ((arr[i] - (n - 1) + i) > 0) {
			ifans[arr[i] - (n - 1) + i]++;
		}
	}
	int mx = 0;
	repi(i,0, 1e5 + 9){
		mx = max(mx,ifans[i]);
	}
	cout << n - mx << endl;



	return 0;
}
